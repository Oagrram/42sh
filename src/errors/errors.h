/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:55:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/01 09:56:02 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error
{
	EACCES = 1,
	ENOCMD,
	ENOENT,
	ENOTDIR,
	ENAMETOOLONG,
	ENOHOME,
	ENOOLDPWD,
	EISDIR,
	EREDIRECT,
	EAMBREDIRECT,
	ESYNTAX,
	ETOOMANYPIPES,
	EFORK,
	EOPENFILE,
	ENOJOB,
	EUNK
}				t_error;

extern t_error	g_errno;

void			ft_perror(char *prefix, char *suffix, t_bool exit_on_error);
void			ft_strerror(t_error e, char *prefix, char *suffix,
					t_bool exit_on_error);

#endif
