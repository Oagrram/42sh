/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:38:07 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/24 16:41:14 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static void	print_job_state_str(t_job *job)
{
	if (job->state == RUNNING)
		ft_printf(1, "Running");
	else if (job->state == STOPPED)
		ft_printf(1, "Stopped (%d)", WSTOPSIG(job->wait_status));
	else if (job->state == COMPLETED && WIFEXITED(job->wait_status))
	{
		ft_printf(1, "Done");
		if (WEXITSTATUS(job->wait_status) != 0)
			ft_printf(1, " (%d)", WEXITSTATUS(job->wait_status));
	}
	else if (job->state == COMPLETED && WIFSIGNALED(job->wait_status))
		ft_printf(1, "Terminated (%d)", WTERMSIG(job->wait_status));
}

void	print_job(t_job *job, t_job_print_mode mode,
	t_special_jobs *special_jobs)
{
	if (mode == PGID)
		ft_printf(1, "%u\n", (int)job->pgid);
	else
	{
		ft_printf(1, "[%d]", job->id);
		if (job == special_jobs->current)
			ft_printf(1, "+");
		else if (job == special_jobs->previous)
			ft_printf(1, "-");
		ft_printf(1, " ");
		if (mode == LONG)
			ft_printf(1, "%d ", job->pgid);
		print_job_state_str(job);
		ft_printf(1, " %s\n", job->job_name);
		job->to_notify = FALSE;
	}
}
