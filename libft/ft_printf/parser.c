/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:06 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:34:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

static void	parse_flags(t_conv_spec *conv_spec, char **conv)
{
	while (1)
	{
		if (**conv == '0')
			conv_spec->flags |= FLAG_ZERO;
		else if (**conv == ' ')
			conv_spec->flags |= FLAG_SPACE;
		else if (**conv == '#')
			conv_spec->flags |= FLAG_HASH;
		else if (**conv == '+')
			conv_spec->flags |= FLAG_PLUS;
		else if (**conv == '-')
			conv_spec->flags |= FLAG_MINUS;
		else
			break ;
		(*conv)++;
	}
	if (conv_spec->flags & FLAG_MINUS && conv_spec->flags & FLAG_ZERO)
		conv_spec->flags ^= FLAG_ZERO;
	if (conv_spec->flags & FLAG_PLUS && conv_spec->flags & FLAG_SPACE)
		conv_spec->flags ^= FLAG_SPACE;
}

static void	parse_width(t_conv_spec *conv_spec, char **conv, va_list *ap)
{
	if ('1' <= **conv && **conv <= '9')
	{
		conv_spec->width = ft_atoi(*conv);
		while (ft_isdigit(**conv))
			(*conv)++;
		if (conv_spec->width < 0)
			conv_spec->width = 0;
	}
	else if (**conv == '*')
	{
		conv_spec->width = va_arg(*ap, int);
		(*conv)++;
		if (conv_spec->width < 0)
		{
			conv_spec->width = ter_i(
					(conv_spec->width <= -2147483648), 0, -conv_spec->width);
			conv_spec->flags |= FLAG_MINUS;
			conv_spec->flags &= ~FLAG_ZERO;
		}
	}
}

static void	parse_precision(t_conv_spec *conv_spec, char **conv, va_list *ap)
{
	if (**conv == '.')
	{
		(*conv)++;
		conv_spec->is_pset = 1;
	}
	else
		return ;
	if (ft_isdigit(**conv))
	{
		conv_spec->precision = ft_atoi(*conv);
		while (ft_isdigit(**conv))
			(*conv)++;
	}
	else if (**conv == '*')
	{
		conv_spec->precision = va_arg(*ap, int);
		(*conv)++;
	}
	if (conv_spec->precision < 0)
	{
		conv_spec->precision = 0;
		conv_spec->is_pset = 0;
	}
}

void	parse_length(t_conv_spec *conv_spec, char **conv)
{
	if (**conv == 'h' && *((*conv) + 1) == 'h')
	{
		conv_spec->length = HH;
		(*conv) += 2;
	}
	else if (**conv == 'l' && *((*conv) + 1) == 'l')
	{
		conv_spec->length = LL;
		(*conv) += 2;
	}
	else if (**conv == 'l')
	{
		conv_spec->length = L;
		(*conv)++;
	}
	else if (**conv == 'h')
	{
		conv_spec->length = H;
		(*conv)++;
	}
	else if (**conv == 'L')
	{
		conv_spec->length = CAPITAL_L;
		(*conv)++;
	}
}

int	parse_conversion(char **conv_str, va_list *ap, int fd)
{
	t_conv_spec	conv_spec;
	char		*c_str;

	c_str = *conv_str;
	ft_bzero(&conv_spec, sizeof(t_conv_spec));
	conv_spec.fd = fd;
	c_str++;
	parse_flags(&conv_spec, &c_str);
	parse_width(&conv_spec, &c_str, ap);
	parse_precision(&conv_spec, &c_str, ap);
	parse_length(&conv_spec, &c_str);
	if (is_in_str(*c_str, "csdiu%"))
	{
		conv_spec.conv_char = *c_str;
		*conv_str = ++c_str;
		return (apply_conv_function(&conv_spec, ap, *(c_str - 1)));
	}
	(*conv_str)++;
	return (1);
}
