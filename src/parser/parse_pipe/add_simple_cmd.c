/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:41:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 11:36:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	parse_pipe_free_all(t_parse_pipe *p_p)
{
	vector_free(p_p->pipe_cmd->commands);
	free(p_p->pipe_cmd);
	vector_free(p_p->cmd_tokens);
	ft_bzero(p_p, sizeof(t_parse_pipe));
	free(p_p);
}

int	handle_error(t_parse_pipe *p_p, t_bool is_last_cmd)
{
	if (g_errno == ESYNTAX && is_last_cmd == FALSE)
	{
		unexpected_token(p_p->current_token.type);
		g_errno = EUNK;
	}
	parse_pipe_free_all(p_p);
	return (EXIT_FAILURE);
}

int	add_simple_cmd(t_parse_pipe *p_p, t_bool is_last_cmd)
{
	t_simple_command	*simple_cmd;

	if (p_p->cmd_tokens->length == 0)
	{
		if (is_last_cmd)
			g_errno = ESYNTAX;
		else
			unexpected_token(p_p->current_token.type);
		return (EXIT_FAILURE);
	}
	simple_cmd = parse_simple_cmd(p_p->cmd_tokens);
	if (simple_cmd == NULL)
		handle_error(p_p, is_last_cmd);
	vector_push(p_p->pipe_cmd->commands, simple_cmd);
	free(simple_cmd);
	vector_free(p_p->cmd_tokens);
	p_p->cmd_tokens = vector_init(sizeof(t_token), NULL);
	return (EXIT_SUCCESS);
}
