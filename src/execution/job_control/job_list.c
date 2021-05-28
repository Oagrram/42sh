/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:06:19 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/06 12:07:40 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_vector	*g_job_list;

/*
	a callback used by vector_init()
*/
static void	free_job(void *job)
{
	t_job	*j;

	j = (t_job *)job;
	ft_strdel(&j->job_name);
	vector_free(j->processes);
}

/* 
	initialize jobs lists.
	this function should be called only once at the start of the program
	along with initialization code.
*/
void	init_jobs(void)
{
	if (g_job_list == NULL)
		g_job_list = vector_init(sizeof(t_job), free_job);
	if (g_stopped_jobs == NULL)
		g_stopped_jobs = vector_init(sizeof(int), NULL);
	return ;
}

void	add_to_job_list(t_job *job)
{
	static int	id = 1;

	if (g_job_list == NULL)
		g_job_list = vector_init(sizeof(t_job), free_job);
	if (g_job_list->length == 0)
		id = 1;
	else
		id++;
	job->id = id;
	vector_push(g_job_list, job);
}

t_job	*get_job_by_id(uint32_t id)
{
	t_job *const	jobs_array = g_job_list->array;
	size_t			i;

	if (g_job_list == NULL)
		g_job_list = vector_init(sizeof(t_job), free_job);
	i = 0;
	while (i < g_job_list->length)
	{
		if (id == jobs_array[i].id)
			return (jobs_array + i);
		i++;
	}
	return (NULL);
}

void	remove_from_job_list(uint32_t job_id)
{
	t_job *const	jobs_array = g_job_list->array;
	size_t			i;

	if (g_job_list == NULL)
		g_job_list = vector_init(sizeof(t_job), free_job);
	i = 0;
	while (i < g_job_list->length)
	{
		if (job_id == jobs_array[i].id)
			vector_remove(g_job_list, i);
		i++;
	}
}
