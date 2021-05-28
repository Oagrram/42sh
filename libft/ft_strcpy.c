/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:50:47 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 12:22:57 by mel-idri         ###   ########.fr       */
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
