/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 11:37:22 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_pipe	*parse_pipe_init(t_vector *tokens_vec)
{
	t_parse_pipe	*ptr;

	ptr = (t_parse_pipe *)ft_malloc(sizeof(t_parse_pipe));
	ptr->pipe_cmd = (t_pipe_sequence *)ft_malloc(sizeof(t_pipe_sequence));
	ptr->pipe_cmd->commands = vector_init(sizeof(t_simple_command),
			free_simple_cmd);
	ptr->cmd_tokens = vector_init(sizeof(t_token), NULL);
	ptr->tokens = (t_token *)tokens_vec->array;
	ptr->tokens_len = tokens_vec->length;
	ptr->tokens_index = 0;
	ptr->current_token = ptr->tokens[ptr->tokens_index];
	return (ptr);
}

static void	parse_pipe_advance(t_parse_pipe *p_p)
{
	++(p_p->tokens_index);
	p_p->current_token = p_p->tokens[p_p->tokens_index];
}

static void	parse_pipe_clean(t_parse_pipe *p_p)
{
	vector_free(p_p->cmd_tokens);
	ft_bzero(p_p, sizeof(t_parse_pipe));
	free(p_p);
}

t_pipe_sequence	*parse_pipe(t_vector *tokens_vec)
{
	t_parse_pipe	*p_p;
	t_pipe_sequence	*pipe_cmd;

	p_p = parse_pipe_init(tokens_vec);
	while (p_p->tokens_index < p_p->tokens_len)
	{
		if (p_p->current_token.type == PIPE)
		{
			if (add_simple_cmd(p_p, FALSE) == EXIT_FAILURE)
				return (NULL);
		}
		else
			vector_push(p_p->cmd_tokens, &(p_p->current_token));
		parse_pipe_advance(p_p);
	}
	if (add_simple_cmd(p_p, TRUE) == EXIT_FAILURE)
		return (NULL);
	pipe_cmd = p_p->pipe_cmd;
	pipe_cmd->job_name = get_job_name(tokens_vec);
	parse_pipe_clean(p_p);
	return (pipe_cmd);
}
