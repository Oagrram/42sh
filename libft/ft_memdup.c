/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:14:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:41:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*s;
	size_t			i;

	if (src != NULL)
		res = (unsigned char *)ft_malloc(n);
	if (src == NULL || res == NULL)
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	return ((void *)res);
}
