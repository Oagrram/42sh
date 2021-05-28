/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:12 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 11:42:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

char	*get_path(char *path);
char	*if_logically(char *path);
int		check_errors(char *path, char *origin_path);
void	show_error_msg(char *path);

void	ft_update_pwd(char *path)
{
	char	*pwd;

	pwd = env_get(g_shell_env, "PWD");
	if (pwd)
		env_set_value(g_shell_env, "OLDPWD", pwd);
	env_set_value(g_shell_env, "PWD", path);
}

int	get_cd_flag(char ***cmd)
{
	char	**tmp;
	int		ret;
	int		i;

	ret = 1;
	tmp = *cmd;
	while (*tmp)
	{
		if (ft_strequ(*tmp, "-") || **tmp != '-')
			break ;
		i = 0;
		while (tmp[0][++i])
		{
			if (tmp[0][i] != 'L' && tmp[0][i] != 'P')
				return (ft_printf(2, "cd", "usage: cd [-L|-P] [dir]\n"));
			ret = tmp[0][i] == 'L';
		}
		tmp++;
	}
	*cmd = tmp;
	return (ret);
}

char	*get_cd_path(char *ret)
{
	char	*pwd;
	char	*tmp;
	char	*path;

	path = get_path(ret);
	if (path && *path && !ft_isinstr(*path, "./"))
	{
		tmp = path;
		path = concat_path_with_cdpath(path);
		if (tmp != path)
			free(tmp);
	}
	if (path && *path && *path != '/'
		&& assign_p(&pwd, env_get(g_shell_env, "PWD")))
	{
		tmp = path;
		path = ft_strnjoin((char *[]){pwd, "/", path}, 3);
		free(tmp);
	}
	return (path);
}

int	ft_cd(char **cmd)
{
	char	*path;
	int		logicaly;

	if (assign_i(&logicaly, get_cd_flag(&cmd)) == -1 || (cmd[0] && cmd[1]))
		return (ter_i(!!cmd[1], ft_printf(2, "cd: to many argument\n"), -1));
	path = get_cd_path(*cmd);
	if (path == NULL)
	{
		show_error_msg(*cmd);
		return (1);
	}
	if (logicaly)
		path = if_logically(path);
	if (!chdir(path))
	{
		if (!logicaly)
		{
			free(path);
			path = getcwd(NULL, 0);
		}
		ft_update_pwd(path);
		free(path);
		return (0);
	}
	return (check_errors(path, *cmd));
}
