/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:07:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:30:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bigint	*calculate_res(t_bigint *base, unsigned int exp)
{
	t_bigint	*res;

	res = ft_bigint_from_uint128(1);
	if (res == NULL)
		return (NULL);
	while (exp > 1)
	{
		if (exp % 2 && (exp-- || 1))
		{
			res = ft_bigint_mult(res, base);
			if (res == NULL)
				return (NULL);
		}
		exp /= 2;
		base = ft_bigint_mult(base, base);
		if (base == NULL)
			return (NULL);
	}
	res = ft_bigint_mult(res, base);
	return (res);
}

t_bigint	*ft_bigint_power(unsigned int b, unsigned int exp)
{
	t_bigint	*base;

	base = ft_bigint_from_uint128(b);
	if (base == NULL)
		return (NULL);
	if (exp <= 0)
		return (ft_bigint_from_uint128(1));
	else if (exp == 1)
		return (base);
	return (calculate_res(base, exp));
}
