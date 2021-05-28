/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:41:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 11:27:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int	size;

	if (s == NULL)
		return (0);
	size = ft_putstr_fd(s, fd);
	size += ft_putchar_fd('\n', fd);
	return (size);
}
