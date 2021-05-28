/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:46 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 17:46:46 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_job	*new_job(t_bool is_background, char *job_name)
{
	t_job	job;

	ft_bzero(&job, sizeof(t_job));
	job.is_background = is_background;
	job.state = RUNNING;
	job.job_name = ft_strdup(job_name);
	job.processes = vector_init(sizeof(t_process), NULL);
	add_to_job_list(&job);
	return (vector_get(g_job_list, g_job_list->length - 1));
}
