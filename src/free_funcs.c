/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:58:07 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/03 13:05:56 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	free_simple_cmd(void *elem)
{
	t_simple_command	*simple_cmd;

	simple_cmd = (t_simple_command *)elem;
	vector_free(simple_cmd->args);
	vector_free(simple_cmd->assignments);
	vector_free(simple_cmd->redirections);
	free(simple_cmd->job_name);
}

void	free_pipe_seq(void *elem)
{
	t_pipe_sequence	*pipe_seq;

	pipe_seq = (t_pipe_sequence *)elem;
	vector_free(pipe_seq->commands);
	free(pipe_seq->job_name);
}

void	free_logic_seq(void *elem)
{
	t_logic_sequence	*logic_seq;

	logic_seq = (t_logic_sequence *)elem;
	vector_free(logic_seq->commands);
	vector_free(logic_seq->logic_ops);
	free(logic_seq->job_name);
}

void	free_command(void *elem)
{
	t_command	*cmd;

	cmd = (t_command *)elem;
	if (cmd->type == LOGIC_SEQ)
		free_logic_seq(cmd->command);
	else if (cmd->type == PIPE_SEQ)
		free_pipe_seq(cmd->command);
	else if (cmd->type == SIMPLE_CMD)
		free_simple_cmd(cmd->command);
	free(cmd->command);
}
