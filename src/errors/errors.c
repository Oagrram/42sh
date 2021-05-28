/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:01:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 14:29:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_error		g_errno;

const char	*g_error_message_string[] = {
	[EACCES] = "Permission denied",
	[ENOCMD] = "Command not found",
	[ENOENT] = "No such file or directory",
	[ENOTDIR] = "Not a directory",
	[ENAMETOOLONG] = "File name too long",
	[ENOHOME] = "HOME not set",
	[ENOOLDPWD] = "OLDPWD not set",
	[EISDIR] = "is a directory",
	[EREDIRECT] = "Redirection error",
	[EAMBREDIRECT] = "ambiguous redirect",
	[ESYNTAX] = "syntax error near unexpected token",
	[ETOOMANYPIPES] = "Too many pipes",
	[EFORK] = "fork error",
	[EOPENFILE] = "cannot open file",
	[ENOJOB] = "no such job",
	[EUNK] = "An error has occured"
};

void	ft_perror(char *prefix, char *suffix, t_bool exit_on_error)
{
	if (g_errno > EUNK)
		g_errno = EUNK;
	ft_putstr_fd("42sh: ", 2);
	if (prefix != NULL)
		ft_printf(2, "%s: ", prefix);
	ft_putstr_fd(g_error_message_string[g_errno], 2);
	if (suffix != NULL)
		ft_printf(2, " %s", suffix);
	ft_putstr_fd("\n", 2);
	if (g_errno > 0 && exit_on_error == TRUE)
		exit(g_errno);
}

void	ft_strerror(t_error e, char *prefix, char *suffix, t_bool exit_on_error)
{
	t_error	tmp_err;

	tmp_err = g_errno;
	g_errno = e;
	ft_perror(prefix, suffix, exit_on_error);
	g_errno = tmp_err;
}
