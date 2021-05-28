/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:52:47 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 16:59:42 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)ft_malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	i = -1;
	while (++i < len2)
		new_str[i + len1] = s2[i];
	new_str[i + len1] = '\0';
	return (new_str);
}
