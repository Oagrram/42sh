/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:56:32 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/23 04:35:29 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	notify_job_state(void)
{
	size_t			i;
	t_job			*job;
	t_special_jobs	special_jobs;

	i = 0;
	special_jobs.current = get_current_job();
	special_jobs.previous = get_previous_job();
	while (i < g_job_list->length)
	{
		job = vector_get(g_job_list, i);
		if (job->to_notify && job->is_background)
		{
			print_job(job, NORMAL, &special_jobs);
			job->to_notify = FALSE;
			if (job->state == COMPLETED)
				remove_from_job_list(job->id);
		}
		i++;
	}
}
