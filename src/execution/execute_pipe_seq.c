/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_seq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 11:38:22 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <stdbool.h>

t_vector	*g_pip_env;

void	ft_execve_pip(char **args, char *full_path, t_vector *red)
{
	char	**a_env;

	a_env = env_to_envp(g_pip_env);
	if (check_builtins(args[0]))
	{
		execute_builtins(args, red);
		exit(g_exit_status);
	}
	else if (args && args[0])
	{
		if (execve(full_path, args, a_env) == -1)
		{
			if (access(full_path, X_OK) == 0)
				ft_strerror(EACCES, args[0], NULL, FALSE);
			else
				ft_strerror(ENOCMD, args[0], NULL, FALSE);
			exit(127);
		}
	}
	else
		exit(0);
}

pid_t	execute_pip_pt2(char **args, pid_t *pgid, t_bool is_background,
	t_vector *red)
{
	pid_t		pid;
	char		*full_path;

	full_path = get_full_path(args[0]);
	pid = fork();
	if (pid == -1)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		if (g_shell_env != g_pip_env)
			vector_free(g_pip_env);
		return (-1);
	}
	set_process_group(ter_i(pid == 0, getpid(), pid), pgid, is_background);
	if (pid == 0)
	{
		reset_signals();
		manage_pipes(2);
		ft_execve_pip(args, full_path, red);
	}
	ft_strdel(&full_path);
	if (g_shell_env != g_pip_env)
		vector_free(g_pip_env);
	backups(2);
	return (pid);
}

t_vector	*execute_pip(t_simple_command *cmd, int len, t_bool is_background)
{
	t_vector	*vec_pid;
	char		**args;
	pid_t		pid;
	int			i;
	pid_t		pgid;

	i = 0;
	pgid = 0;
	vec_pid = vector_init(sizeof(pid_t), NULL);
	while (i < len)
	{
		expand_args(cmd[i].args);
		do_value(cmd[i].assignments, cmd[i].args->length, &g_pip_env);
		vector_push(cmd[i].args, &(char *){NULL});
		args = (char **)cmd[i].args->array;
		remove_quotes_from_args(args);
		if (do_pipes_and_red(i, len, cmd[i].redirections) == 1)
			return (NULL);
		pid = execute_pip_pt2(args, &pgid, is_background, cmd[i].redirections);
		if (pid == -1)
			return (NULL);
		vector_push(vec_pid, &pid);
		i++;
	}
	return (vec_pid);
}

int	execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background)
{
	t_simple_command	*s_cmd;
	t_vector			*vec_pid;
	pid_t				*pid;
	pid_t				f_pid;
	int					i;

	s_cmd = (t_simple_command *)pipe_seq->commands->array;
	vec_pid = execute_pip(s_cmd, pipe_seq->commands->length, is_background);
	if (vec_pid)
	{
		i = -1;
		pid = (pid_t *)vec_pid->array;
		while (++i < (int)vec_pid->length)
			f_pid = pid[i];
		if (g_is_job_enabled == FALSE)
		{
			i = get_exit_code(wait_children(f_pid));
			vector_free(vec_pid);
			return (i);
		}
		else
			return (execute_job(vec_pid, pipe_seq->job_name, is_background));
	}
	return (g_exit_status);
}
