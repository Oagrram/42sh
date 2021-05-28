/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:46:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 11:07:03 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*get_job_name(t_vector *tokens_vec)
{
	t_token	*tokens;
	char	*job_name;
	char	*token_str;
	size_t	i;

	i = 0;
	job_name = ft_strdup("");
	tokens = tokens_vec->array;
	while (i < tokens_vec->length)
	{
		job_name = ft_strjoin_free(job_name, " ", 1, 0);
		if (tokens[i].type == WORD || tokens[i].type == IO_NUMBER)
			token_str = tokens[i].data;
		else
			token_str = g_tokens_to_symbol[tokens[i].type];
		job_name = ft_strjoin_free(job_name, token_str, 1, 0);
		++i;
	}
	return (job_name);
}
