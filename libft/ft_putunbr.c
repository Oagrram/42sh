/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:04 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:45:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n / 10)
		ret += ft_putunbr(n / 10);
	return (ret + ft_putchar(n % 10 + '0'));
}
