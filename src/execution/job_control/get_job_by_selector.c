/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_by_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:18:03 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 17:56:46 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static t_job	*match_job_name_start(char *job_name_start)
{
	t_job	*job;
	size_t	i;
	size_t	job_name_start_len;

	i = 0;
	job_name_start_len = ft_strlen(job_name_start);
	while (i < g_job_list->length)
	{
		job = vector_get(g_job_list, i);
		if (ft_strncmp(job_name_start, job->job_name, job_name_start_len) == 0)
			return (job);
		i++;
	}
	return (NULL);
}

static t_job	*match_job_name_contains(char *job_name_pattern)
{
	t_job	*job;
	size_t	i;

	i = 0;
	while (i < g_job_list->length)
	{
		job = vector_get(g_job_list, i);
		if (ft_strstr(job->job_name, job_name_pattern))
			return (job);
		i++;
	}
	return (NULL);
}

t_job	*get_job_by_selector(char *job_selector)
{
	if (job_selector[0] != '%')
		return (NULL);
	job_selector++;
	if (job_selector[0] == '%' || job_selector[0] == '+')
		return (get_current_job());
	else if (job_selector[0] == '-')
		return (get_previous_job());
	else if (ft_str_isnumeric(job_selector))
	{
		if (ft_atoi(job_selector) > 0
			&& (size_t)ft_atoi(job_selector) <= g_job_list->length)
			return (get_job_by_id(ft_atoi(job_selector)));
	}
	else if (job_selector[0] == '?')
	{
		if (job_selector[1])
			return (match_job_name_contains(job_selector + 1));
	}
	else if (job_selector[0])
		return (match_job_name_start(job_selector));
	return (NULL);
}
