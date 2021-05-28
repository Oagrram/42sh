/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:58:29 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:46:33 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** find `c` in `src` and copy upto `c`(included) to `dst`
** and return a pointer to the character after `c` in `dst`
**
** src : *******c****
**       |______|
**     copy this part
**
** dst : *******c**** (after copy)
**   return this ^
**
** otherwise copy everything upto `n` and return NULL
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*c_ptr;
	size_t	len;

	c_ptr = ft_memchr(src, c, n);
	if (c_ptr != NULL)
	{
		len = (unsigned char *)c_ptr - (unsigned char *)src + 1;
		ft_memcpy(dst, src, len);
		return ((void *)((unsigned char *)dst + len));
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
}
