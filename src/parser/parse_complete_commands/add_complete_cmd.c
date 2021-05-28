/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_complete_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:02:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 11:11:28 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	*get_command_by_type(t_parse_complete *parser)
{
	void	*command;

	g_errno = EXIT_SUCCESS;
	if (parser->cmd_type == SIMPLE_CMD)
		command = parse_simple_cmd(parser->cmd_tokens);
	else if (parser->cmd_type == PIPE_SEQ)
		command = parse_pipe(parser->cmd_tokens);
	else
		command = parse_and_or(parser->cmd_tokens);
	if (command == NULL && g_errno == ESYNTAX)
		unexpected_token(parser->current_token.type);
	return (command);
}

int	add_complete_cmd(t_parse_complete *parser)
{
	t_command	cmd;

	if (parser->cmd_tokens->length == 0)
	{
		unexpected_token(parser->current_token.type);
		return (EXIT_FAILURE);
	}
	cmd.type = parser->cmd_type;
	cmd.is_background_job = parser->current_token.type == AMPERSAND;
	cmd.command = get_command_by_type(parser);
	if (cmd.command == NULL)
		return (EXIT_FAILURE);
	vector_push(parser->commands, &cmd);
	reset_cmd_tokens(parser);
	parser->cmd_type = SIMPLE_CMD;
	return (EXIT_SUCCESS);
}
