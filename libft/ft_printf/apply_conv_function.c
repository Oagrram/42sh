/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_conv_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:34:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

int	apply_conv_function(t_conv_spec *conv_spec, va_list *ap, int c)
{
	if (c == 'd' || c == 'i')
		return (conv_di(conv_spec, ap));
	if (c == 'u')
		return (conv_u(conv_spec, ap));
	if (c == 'c')
		return (conv_c(conv_spec, ap));
	if (c == 's')
		return (conv_s(conv_spec, ap));
	if (c == '%')
		return (conv_percenatge(conv_spec));
	return (0);
}
