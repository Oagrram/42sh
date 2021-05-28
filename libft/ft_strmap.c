/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:19:36 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:52:25 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	size;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((const char *)s);
	new_str = (char *)ft_malloc(size + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
