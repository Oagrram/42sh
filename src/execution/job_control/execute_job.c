/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:21:23 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/02 17:12:30 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_bool	g_is_job_enabled = TRUE;

/*
create vector from a single pid 
*/
t_vector	*pid2vec(pid_t pid)
{
	t_vector	*vec;

	vec = vector_init(sizeof(pid_t), NULL);
	vector_push(vec, &pid);
	return (vec);
}

int	execute_job(t_vector *pids_vec, char *job_name, t_bool is_background)
{
	size_t	i;
	pid_t	*pid;
	t_job	*job;

	if (pids_vec == NULL || pids_vec->length == 0)
	{
		ft_printf(2, "42sh: job has no process");
		return (1);
	}
	if (pids_vec->length > 0)
		job = new_job(is_background, job_name);
	i = 0;
	while (i < pids_vec->length)
	{
		pid = vector_get(pids_vec, i);
		add_process_to_job(job, *pid);
		i++;
	}
	job->ret_pid = *pid;
	vector_free(pids_vec);
	if (is_background)
		ft_printf(1, "[%d] %d\n", job->id, job->ret_pid);
	else
		return (get_exit_code(wait_job(job)));
	return (0);
}
