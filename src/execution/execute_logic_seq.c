/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_logic_seq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:42:48 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 11:23:18 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	execute_logical_segment(t_command *cmd, t_bool is_background)
{
	int	ret;

	backups(3);
	backups(1);
	if (cmd->type == PIPE_SEQ)
		ret = execute_pipe_seq((t_pipe_sequence *)cmd->command, is_background);
	else
		ret = execute_simple_cmd((t_simple_command *)cmd->command,
				is_background);
	backups(3);
	return (ret);
}

static int	logic_seq_executor(t_logic_sequence *logic_seq,
	t_bool is_background)
{
	int					ret;
	int					i;
	t_command *const	cmds = logic_seq->commands->array;
	t_token_type *const	ops = logic_seq->logic_ops->array;

	i = 0;
	ret = execute_logical_segment(&cmds[0], is_background);
	while (i < (int)logic_seq->logic_ops->length)
	{
		if ((ret == 0 && ops[i] == ANDAND)
			|| (ret != 0 && ops[i] == OROR))
			ret = execute_logical_segment(&cmds[i + 1], is_background);
		i++;
	}
	return (ret);
}

static int	execute_logic_seq_background(t_logic_sequence *logic_seq)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return (-1);
	}
	set_process_group(ter_i(pid, getpid(), pid), &(int){0}, TRUE);
	if (pid == 0)
	{
		g_is_job_enabled = FALSE;
		setup_disabled_job_signals();
		exit(logic_seq_executor(logic_seq, TRUE));
	}
	if (g_is_job_enabled)
		return (execute_job(pid2vec(pid), logic_seq->job_name, TRUE));
	return (0);
}

int	execute_logic_seq(t_logic_sequence *logic_seq, t_bool is_background)
{
	if (is_background)
		return (execute_logic_seq_background(logic_seq));
	else
		return (logic_seq_executor(logic_seq, FALSE));
}
