/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:37:11 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 15:43:22 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	*get_cmd(t_parse_and_or *and_or, t_bool is_last_cmd)
{
	t_command	*cmd;

	cmd = (t_command *)ft_malloc(sizeof(t_command));
	cmd->type = and_or->cmd_type;
	cmd->is_background_job = FALSE;
	if (cmd->type == SIMPLE_CMD)
		cmd->command = parse_simple_cmd(and_or->cmd_tokens);
	else if (cmd->type == PIPE_SEQ)
		cmd->command = parse_pipe(and_or->cmd_tokens);
	if (cmd->command == NULL)
	{
		if (g_errno == ESYNTAX && is_last_cmd == FALSE)
		{
			g_errno = EUNK;
			unexpected_token(and_or->current_token.type);
		}
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

int	and_or_push_command(t_parse_and_or *and_or, t_bool is_last_cmd)
{
	t_command	*cmd;

	if (and_or->cmd_tokens->length == 0)
	{
		if (is_last_cmd)
			g_errno = ESYNTAX;
		else
			unexpected_token(and_or->current_token.type);
		return (EXIT_FAILURE);
	}
	cmd = get_cmd(and_or, is_last_cmd);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	vector_push(and_or->logic_cmd->commands, cmd);
	free(cmd);
	and_or->cmd_tokens->length = 0;
	and_or->cmd_type = SIMPLE_CMD;
	return (EXIT_SUCCESS);
}
