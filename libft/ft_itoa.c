/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:45:26 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:34:25 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*res;
	size_t			size;
	int				index;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	size = ft_nbrlen(nb) + (n < 0);
	res = ft_strnew(size);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	index = size - 1;
	while (nb > 0)
	{
		res[index] = nb % 10 + '0';
		nb /= 10;
		index--;
	}
	return (res);
}
