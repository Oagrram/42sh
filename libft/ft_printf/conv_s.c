/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 00:12:42 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:34:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

int	conv_s(t_conv_spec *conv_spec, va_list *ap)
{
	int		str_len;
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	str_len = ter_i(conv_spec->is_pset && conv_spec->precision < str_len,
			conv_spec->precision, str_len);
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar_fd(' ', conv_spec->width - str_len, conv_spec->fd);
	ft_putstr_fd(str, conv_spec->fd);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', conv_spec->width - str_len, conv_spec->fd);
	return (ter_i(conv_spec->width > str_len, conv_spec->width, str_len));
}
