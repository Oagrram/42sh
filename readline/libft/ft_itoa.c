/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:08:01 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:41 by hmzah            ###   ########.fr       */
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
