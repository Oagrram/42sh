/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:11:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:51:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strglue(char const *s1, char glue, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = ft_strnew(len1 + len2 + 2);
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	new_str[i++] = glue;
	i = -1;
	while (++i < len2)
		new_str[i + len1 + 1] = s2[i];
	new_str[i + len1 + 1] = '\0';
	return (new_str);
}
