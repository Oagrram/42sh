/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 15:27:50 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	backups(int f)
{
	static int	stdii;
	static int	stdou;
	static int	stder;

	if (f == 1)
	{
		stdii = dup2(0, 199);
		stdou = dup2(1, 200);
		stder = dup2(2, 201);
	}
	else
	{
		dup2(stdii, 0);
		dup2(stdou, 1);
		dup2(stder, 2);
		if (f == 3)
		{
			close(stdii);
			close(stdou);
			close(stder);
		}
	}
}

void	execute_commands(t_vector *commands)
{
	t_command *const	cmds_array = commands->array;
	int					i;

	i = 0;
	while (i < (int)commands->length)
	{
		backups(1);
		if (cmds_array[i].type == LOGIC_SEQ)
			g_exit_status = execute_logic_seq(cmds_array[i].command,
					cmds_array[i].is_background_job);
		else if (cmds_array[i].type == PIPE_SEQ)
			g_exit_status = execute_pipe_seq(cmds_array[i].command,
					cmds_array[i].is_background_job);
		else if (cmds_array[i].type == SIMPLE_CMD)
			g_exit_status = execute_simple_cmd(cmds_array[i].command,
					cmds_array[i].is_background_job);
		i++;
		backups(3);
	}
}
