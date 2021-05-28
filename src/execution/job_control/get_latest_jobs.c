/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_latest_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:05:06 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/19 23:28:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static	int	get_before_last_background_job_id(void)
{
	t_job *const	jobs = g_job_list->array;
	int				i;
	t_bool			cross_last_background_job;

	i = g_job_list->length - 1;
	cross_last_background_job = FALSE;
	while (i > 0)
	{
		if (jobs[i].is_background && jobs[i].state != STOPPED)
		{
			if (!cross_last_background_job)
				cross_last_background_job = TRUE;
			else
				return (jobs[i].id);
		}
		--i;
	}
	return (0);
}

static	int	get_last_background_job_id(void)
{
	t_job *const	jobs = g_job_list->array;
	int				i;

	i = g_job_list->length - 1;
	while (i > 0)
	{
		if (jobs[i].is_background && jobs[i].state != STOPPED)
			return (jobs[i].id);
		--i;
	}
	return (0);
}

t_job	*get_current_job(void)
{
	int		id;

	id = 0;
	if (g_stopped_jobs->length > 0)
		id = *(int *)vector_get(g_stopped_jobs, g_stopped_jobs->length - 1);
	else if (g_job_list->length > 0)
		id = get_last_background_job_id();
	if (id != 0)
		return (get_job_by_id(id));
	return (NULL);
}

t_job	*get_previous_job(void)
{
	int	id;

	id = 0;
	if (g_stopped_jobs->length > 1)
		id = *(int *)vector_get(g_stopped_jobs, g_stopped_jobs->length - 2);
	else if (g_stopped_jobs->length == 1)
	{
		if (g_job_list->length - g_stopped_jobs->length > 0)
			id = get_last_background_job_id();
		else
			id = *(int *)vector_get(g_stopped_jobs, g_stopped_jobs->length - 1);
	}
	else
	{
		if (g_job_list->length - g_stopped_jobs->length > 1)
			id = get_before_last_background_job_id();
		else if (g_job_list->length - g_stopped_jobs->length == 1)
			id = get_last_background_job_id();
	}
	if (id != 0)
		return (get_job_by_id(id));
	return (NULL);
}
