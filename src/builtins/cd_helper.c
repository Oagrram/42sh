/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:16 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 10:43:06 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <dirent.h>

int	is_correct_path(char *path, int print_error)
{
	DIR	*dir;

	if (path && !access(path, F_OK))
	{
		dir = opendir(path);
		if (!dir)
		{
			if (print_error)
				ft_printf(2, "cd: %s: Not a directory\n", path);
			return (0);
		}
		closedir(dir);
		return (1);
	}
	if (print_error)
		ft_printf(2, "cd: %s: No such file or directory\n", path);
	return (0);
}

char	*get_path_var(const char *key, int get_current_dir)
{
	char	*var;

	var = env_get(g_shell_env, (char *)key);
	if (var)
		return (ft_strdup(var));
	if (get_current_dir)
		return (getcwd(NULL, 0));
	return (NULL);
}

char	*concat_path_with_cdpath(char *path)
{
	char		*tmp;
	char		**cd_paths;
	char		*var;
	int			i;

	i = 0;
	var = env_get(g_shell_env, "CDPATH");
	cd_paths = ft_strsplit(var, ' ');
	if (cd_paths)
	{
		while (cd_paths[i])
		{
			tmp = ft_strnjoin((char *[]){cd_paths[i++], "/", path}, 3);
			if (is_correct_path(tmp, 0))
			{
				free(path);
				path = tmp;
				break ;
			}
			free(tmp);
		}
		ft_free_strings_array(cd_paths);
	}
	return (path);
}
