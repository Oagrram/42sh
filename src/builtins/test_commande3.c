/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commande3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <oagrram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:17:41 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/06 13:21:34 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	check_unary_op2(t_tokens *tokens, t_test_flags flags, struct stat	buf)
{
	if (flags == FlAG_G)
		return (!(buf.st_mode & S_IXGRP));
	if (flags == FlAG_L)
		return (!(S_ISLNK(buf.st_mode)));
	if (flags == FlAG_P)
		return (!(buf.st_mode & S_IFIFO));
	if (flags == FlAG_R && access(tokens->next->data, R_OK) == 0)
		return (!(access(tokens->next->data, R_OK) == 0));
	if (flags == FlAG_SS)
		return (!(buf.st_mode & S_IFSOCK));
	if (flags == FlAG_S)
		return (!(buf.st_size > 0));
	if (flags == FlAG_U)
		return (!(buf.st_mode & S_ISGID));
	if (flags == FlAG_W)
		return (!(access(tokens->next->data, W_OK) == 0));
	if (flags == FlAG_X)
		return (!(access(tokens->next->data, X_OK) == 0));
	if (flags == FlAG_Z)
		return (!(ft_strlen(tokens->next->data) == 0));
	return (-1);
}

int	check_unary_op(t_tokens *tokens)
{
	int				ret;
	t_test_flags	flags;
	struct stat		buf;

	ft_bzero(&buf, sizeof(stat));
	lstat(tokens->next->data, &buf);
	flags = check_flags_test(tokens);
	if (flags == FlAG_B)
		return (!(buf.st_mode & S_IFBLK));
	if (flags == FlAG_C)
		return (!(buf.st_mode & S_IFCHR));
	if (flags == FlAG_D)
		return (!(S_ISDIR(buf.st_mode)));
	if (flags == FlAG_E)
		return (!(access(tokens->next->data, F_OK) == 0));
	if (flags == FlAG_F)
		return (!((access(tokens->next->data, F_OK) == 0)
				&& (buf.st_mode & S_IFREG)));
	ret = check_unary_op2(tokens, flags, buf);
	if (ret != -1)
		return (ret);
	ft_error_unary(tokens->data);
	return (2);
}

int	check_binary_op(t_tokens *tokens)
{
	t_test_operation	ope;

	ope = ft_check_operateur(tokens->next);
	if (ope == OPERATER_E)
		return (!(ft_strequ(tokens->data, tokens->next->next->data)));
	if (ope == OPERATER_RE)
		return ((ft_strequ(tokens->data, tokens->next->next->data)));
	if (ope == OPERATER_AL_E)
		return (ft_binary(tokens->data, tokens->next->next->data, ope));
	if (ope == OPERATER_NO_AL_R)
		return (!(ft_binary(tokens->data, tokens->next->next->data, ope)));
	if (ope == OPERATER_AL_G)
		return (ft_binary(tokens->data, tokens->next->next->data, ope));
	if (ope == OPERATER_AL_L)
		return (!(ft_binary(tokens->data, tokens->next->next->data, ope)));
	if (ope == OPERATER_AL_L_E)
		return (ft_binary(tokens->data, tokens->next->next->data, ope));
	ft_error_binary(tokens->data);
	return (1);
}

void	ft_error_binary(char *error)
{
	ft_putstr_fd("42_sh: test:", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(": binary operator expected", 2);
}
