/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:57:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/07 11:35:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_vector	*g_red;
t_vector	*g_temp_env;

void	ft_execve(char *full_path, char **cmd)
{
	char	**a_env;

	a_env = env_to_envp(g_temp_env);
	if (execve(full_path, cmd, a_env) == -1)
	{
		if (access(full_path, F_OK) == 0)
			ft_strerror(EACCES, cmd[0], NULL, FALSE);
		else
			ft_strerror(ENOCMD, cmd[0], NULL, FALSE);
		exit(127);
	}
}

void	ft_execve_scmd(char **cmd, t_vector **vec_pid,
	t_bool is_b)
{
	pid_t		pid;
	char		*full_path;

	full_path = get_full_path(cmd[0]);
	pid = fork();
	if (pid == -1)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return ;
	}
	set_process_group(ter_i(pid == 0, getpid(), pid), (int [1]){0}, is_b);
	if (pid == 0)
	{
		reset_signals();
		if (check_builtins(cmd[0]))
		{
			execute_builtins(cmd, g_red);
			exit(g_exit_status);
		}
		else
			ft_execve(full_path, cmd);
	}
	ft_strdel(&full_path);
	*vec_pid = vector_init(sizeof(pid_t), NULL);
	vector_push(*vec_pid, &pid);
}

int	exec_pt2(char **cmd, t_vector *red, t_vector **p_vec, t_bool is_background)
{
	g_red = red;
	remove_quotes_from_args(cmd);
	if (do_pipes_and_red(0, 0, red) == 1)
	{
		if (g_shell_env != g_temp_env)
			vector_free(g_temp_env);
		g_temp_env = NULL;
		return (-1);
	}
	if (cmd[0] == NULL)
		return (EXIT_SUCCESS);
	if (check_builtins((cmd)[0]) && is_background == FALSE)
		execute_builtins(cmd, red);
	else
		ft_execve_scmd(cmd, p_vec, is_background);
	if (g_shell_env != g_temp_env)
		vector_free(g_temp_env);
	g_temp_env = NULL;
	backups(3);
	return (EXIT_SUCCESS);
}

void	do_value(t_vector *values, size_t args_len, t_vector **env)
{
	t_var	*vars;
	int		i;

	if (args_len > 0)
		*env = env_dup(g_shell_env);
	else
		*env = g_shell_env;
	vars = (t_var *)values->array;
	i = 0;
	while (i < (int)values->length)
	{
		if (args_len > 0)
			env_set(*env, vars[i].key, vars[i].value, TRUE);
		else
			env_set_value(*env, vars[i].key, vars[i].value);
		i++;
	}
}

int	execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background)
{
	t_vector	*vec_pid;
	char		**cmd;
	int			exit_code;

	vec_pid = NULL;
	if (expand_args(simple_cmd->args))
		return (1);
	do_value(simple_cmd->assignments, simple_cmd->args->length, &g_temp_env);
	vector_push(simple_cmd->args, &(char *){NULL});
	cmd = (char **)simple_cmd->args->array;
	if (exec_pt2(cmd, simple_cmd->redirections, &vec_pid, is_background)
		== -1)
		return (-1);
	if (vec_pid == NULL)
		return (g_exit_status);
	if (g_is_job_enabled == FALSE)
	{
		exit_code = get_exit_code(wait_children((pid_t)vec_pid->array));
		vector_free(vec_pid);
		return (exit_code);
	}
	else
		return (execute_job(vec_pid, simple_cmd->job_name, is_background));
}
