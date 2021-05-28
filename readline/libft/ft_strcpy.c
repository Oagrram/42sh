/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:50:47 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:40:34 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ret;

	if (dst == NULL || src == NULL)
		return (NULL);
	ret = dst;
	while (1)
	{
		*dst = *src;
		if (*dst == '\0')
			break ;
		++dst;
		++src;
	}
	return (ret);
}
