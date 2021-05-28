/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:05 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:36:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_H
# define FT_PRINTF_INTERNALS_H

# include "../libft.h"
# include <stdarg.h>

# define FLAG_ZERO 1U
# define FLAG_HASH 2U
# define FLAG_SPACE 4U
# define FLAG_PLUS 8U
# define FLAG_MINUS 16U
# define ZERO 0
# define INF 1
# define NAN 2
# define FLOAT 3

typedef enum e_length
{
	HH = 1,
	H,
	L,
	LL,
	CAPITAL_L
}					t_length;

typedef struct s_conv_spec
{
	__uint64_t		flags;
	int				width;
	int				is_pset;
	int				precision;
	int				fd;
	t_length		length;
	char			conv_char;
}					t_conv_spec;

typedef struct s_specs
{
	__uint64_t	unbr;
	int			sign;
	int			unbr_len;
	int			spaces;
	int			zeros;
}					t_specs;

int					parse_conversion(char **conv_str, va_list *ap, int fd);
int					apply_conv_function(t_conv_spec *conv_spec, va_list *ap,
						int c);
int					is_in_str(int c, char *str);
int					conv_di(t_conv_spec *conv_spec, va_list *ap);
int					conv_u(t_conv_spec *conv_spec, va_list *ap);
int					conv_c(t_conv_spec *conv_spec, va_list *ap);
int					conv_s(t_conv_spec *conv_spec, va_list *ap);
int					conv_percenatge(t_conv_spec *conv_spec);
__int64_t			read_int(va_list *ap, t_length len);
__uint64_t			read_uint(va_list *ap, t_length len);
int					bit_is_set(unsigned long nbr, int index);

#endif
