/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:48:30 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:34:10 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

int	conv_c(t_conv_spec *conv_spec, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	ft_putchar_fd(c, 1);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	return (ter_i(conv_spec->width, conv_spec->width, 1));
}
