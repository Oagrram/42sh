/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:07:09 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:24:02 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint	*ft_bigint_new(unsigned int size)
{
	t_bigint	*bg_int;

	bg_int = (t_bigint *)ft_autoalloc(sizeof(t_bigint));
	if (bg_int == NULL)
		return (NULL);
	bg_int->length = size;
	bg_int->digits = (char *)ft_autoalloc(size);
	if (bg_int->digits == NULL)
		return (NULL);
	return (bg_int);
}

t_bigint	*ft_bigint_from_uint128(__uint128_t unbr)
{
	int			len;
	int			i;
	t_bigint	*bg_int;

	len = ft_nbrlen(unbr);
	bg_int = ft_bigint_new(len);
	if (bg_int == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bg_int->digits[i] = unbr % 10;
		unbr /= 10;
		i++;
	}
	return (bg_int);
}
