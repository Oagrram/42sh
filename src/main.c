/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/06 15:01:57 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_t				*g_hash;
t_vector		*g_stopped_jobs;
int				g_exit_status;
int				g_term_fd;
char			*g_path_env;

static t_bool	is_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		++i;
	if (line[i] == '\0')
		return (TRUE);
	return (FALSE);
}

int	shell_main(void)
{
	t_vector	*commands;
	char		*cmd_line;

	update_all_jobs();
	notify_job_state();
	cmd_line = read_cmd_multiline();
	if (cmd_line && !is_empty_line(cmd_line))
	{
		add_hist_entry(cmd_line);
		commands = parser(cmd_line);
		if (commands && commands->length > 0)
			execute_commands(commands);
		vector_free(commands);
	}
	ft_strdel(&cmd_line);
	return (EXIT_SUCCESS);
}

int	sh_system(char *line)
{
	t_vector	*commands;

	g_is_job_enabled = FALSE;
	setup_disabled_job_signals();
	if (line == NULL)
		return (-1);
	commands = parser(line);
	if (commands && commands->length > 0)
		execute_commands(commands);
	if (g_hash)
		free_hash(&g_hash);
	return (g_exit_status);
}

int	main(int ac, char *av[], char *envp[])
{
	(void)av;
	g_hash = NULL;
	g_shell_env = env_init(envp);
	setup_enabled_job_signals();
	init_jobs();
	if (ac == 1)
	{
		g_term_fd = open("/dev/tty", O_RDWR);
		if (g_term_fd == -1)
			ft_strerror(EOPENFILE, "open", NULL, TRUE);
		while (1)
			(void)shell_main();
		if (g_hash)
			free_hash(&g_hash);
		if (g_shell_env)
			vector_free(g_shell_env);
	}
	else if (ac == 2)
		return (sh_system(av[1]));
	else
		ft_printf(2, "Error\nusage: ./42sh  [command]\n");
	return (0);
}
