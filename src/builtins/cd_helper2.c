/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:20 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 11:41:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <dirent.h>

char	*ft_get_cwd(char *path, char *ret, char *tmp, char *tmp2)
{
	int			df;

	*ret = 0;
	while (*path)
	{
		if (assign_p(&tmp, ft_skip_unitl_char(path, "/", NULL)))
		{
			if (assign_i(&df, tmp - path) == 2 && ft_strnequ(path, "..", 2))
			{
				if (*ret && assign_p(&tmp2, ft_strrchr(ret, '/')))
					*tmp2 = 0;
			}
			else if (df && (df != 1 || *path != '.'))
			{
				if (assign_p(&tmp2, ft_strchr(ret, 0))
					&& (!*ret || tmp2[-1] != 47))
					ft_strcat(tmp2, "/");
				ft_strncat(tmp2 + 1, path, df);
			}
			path += df + !!*tmp;
		}
	}
	return (ter_p(ret && !*ret, ft_strcat(ret, "/"), ret));
}

char	*get_path(char *path)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup(path);
	if (!ret)
	{
		ret = ft_strdup(env_get(g_shell_env, "HOME"));
		if (ret == NULL)
			g_errno = ENOHOME;
	}
	else if (ft_strequ(path, "-"))
	{
		tmp = ret;
		ret = ft_strdup(env_get(g_shell_env, "OLDPWD"));
		if (ret == NULL)
			g_errno = ENOOLDPWD;
		free(tmp);
	}
	return (ret);
}

char	*if_logically(char *path)
{
	char	*ret;

	ret = ft_get_cwd(path, ft_strdup(path), NULL, NULL);
	free(path);
	return (ret);
}

void	show_error_msg(char *path)
{
	char	*error_prefix;

	error_prefix = ft_strdup("cd");
	if (g_errno != ENOHOME && g_errno != ENOOLDPWD)
	{
		error_prefix = ft_strjoin_free(error_prefix, ": ", 1, 0);
		error_prefix = ft_strjoin_free(error_prefix, path, 1, 0);
	}
	ft_perror(error_prefix, NULL, FALSE);
	free(error_prefix);
}

	// DIR	*dir;

	// dir = opendir(path);
	// free(path);
	// if (dir != NULL)
	// 	ft_printf(2, "cd: permission denied\n");
	// else
	// 	ft_printf(2, "cd: directory not found\n");
int	check_errors(char *path, char *origin_path)
{
	struct stat	st;
	int			err;

	err = 0;
	ft_bzero(&st, sizeof(struct stat));
	if (lstat(path, &st) == -1)
		err = 1;
	if (stat(path, &st) == -1)
		err = 1;
	if (S_ISLNK(st.st_mode) && err == 1)
		g_errno = EUNK;
	else if (access(path, F_OK) == -1)
		g_errno = ENOENT;
	else if (access(path, R_OK) == -1)
		g_errno = EACCES;
	else if (S_ISDIR(st.st_mode))
		g_errno = EXIT_SUCCESS;
	else
		g_errno = ENOTDIR;
	show_error_msg(origin_path);
	return (15);
}
