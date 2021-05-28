/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:54:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/29 17:52:57 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static t_process	new_process(pid_t pid)
{
	t_process	proc;

	proc.state = RUNNING;
	proc.wait_status = 0;
	proc.pid = pid;
	return (proc);
}

void	set_process_group(pid_t pid, pid_t *pgid, t_bool is_background)
{
	if (*pgid == 0)
	{
		setpgid(pid, pid);
		*pgid = pid;
		if (is_background == FALSE)
			tcsetpgrp(g_term_fd, *pgid);
	}
	else if (*pgid > 0)
		setpgid(pid, *pgid);
}

void	add_process_to_job(t_job *job, pid_t pid)
{
	t_process	proc;

	if (job->processes->length == 0)
		job->pgid = pid;
	proc = new_process(pid);
	vector_push(job->processes, &proc);
	job->count.running++;
}

t_process	*get_process_from_job(t_job *job, pid_t pid)
{
	t_process *const	proc_array = job->processes->array;
	size_t				i;

	i = 0;
	while (i < job->processes->length)
	{
		if (pid == proc_array[i].pid)
			return (proc_array + i);
		i++;
	}
	return (NULL);
}

void	remove_process_from_job(t_job *job, pid_t pid)
{
	t_process *const	proc_array = job->processes->array;
	size_t				i;

	i = 0;
	while (i < job->processes->length)
	{
		if (pid == proc_array[i].pid)
		{
			vector_remove(job->processes, i);
			return ;
		}
		i++;
	}
}
