/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:22:37 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 09:15:16 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	print_selected_jobs(char **selectors, t_job_print_mode mode,
	t_special_jobs *special_jobs)
{
	int		ret;
	int		i;
	t_job	*job;

	ret = 0;
	i = 0;
	while (selectors[i])
	{
		job = get_job_by_selector(selectors[i]);
		if (job == NULL)
		{
			ret = 1;
			ft_printf(2, "42sh: jobs: %s no such job\n", selectors[i]);
		}
		else
			print_job(job, mode, special_jobs);
		i++;
	}
	return (ret);
}

int	ft_fg(char **args)
{
	t_job	*job;

	++args;
	if (args[0])
		job = get_job_by_selector(args[0]);
	else
		job = get_current_job();
	if (job == NULL)
	{
		ft_printf(2, "42sh: fg: no such job\n");
		return (1);
	}
	ft_printf(1, "%s\n", job->job_name);
	job->is_background = FALSE;
	tcsetpgrp(g_term_fd, job->pgid);
	kill(-job->pgid, SIGCONT);
	update_job(job);
	return (wait_job(job));
}

int	ft_bg(char **args)
{
	int		ret;
	int		i;
	t_job	*job;

	++args;
	i = 0;
	ret = 0;
	if (*args == NULL)
		args = (char *[2]){"%+", NULL};
	while (*args)
	{
		job = get_job_by_selector(*args);
		if (job == NULL)
		{
			ret = 1;
			ft_printf(2, "42sh: bg: %s: no such job\n", *args);
			args++;
			continue ;
		}
		kill(-job->pgid, SIGCONT);
		update_job(job);
		ft_printf(1, "[%d] %s\n", job->id, job->job_name);
		args++;
	}
	return (ret);
}

int	ft_jobs(char **args)
{
	t_job_print_mode	mode;
	size_t				i;
	int					ret;
	t_special_jobs		special_jobs;

	++args;
	mode = NORMAL;
	if (ft_strequ(args[0], "-p") && args++)
		mode = PGID;
	else if (ft_strequ(args[0], "-l") && args++)
		mode = LONG;
	special_jobs.current = get_current_job();
	special_jobs.previous = get_previous_job();
	i = 0;
	if (*args == NULL)
	{
		while (i < g_job_list->length)
			print_job(vector_get(g_job_list, i++), mode, &special_jobs);
		return (0);
	}
	ret = print_selected_jobs(args, mode, &special_jobs);
	return (ret);
}
