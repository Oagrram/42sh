/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:27:49 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:41:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int nbr, unsigned int exp)
{
	long long	res;

	res = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			res *= nbr;
		exp >>= 1;
		nbr *= nbr;
	}
	return (res);
}
