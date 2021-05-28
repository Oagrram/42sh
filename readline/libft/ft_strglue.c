/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:11:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:36:03 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strglue(char const *s1, char glue, char const *s2)
{
	char	*new_str;
	size_t	len;
	size_t	s1_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	len = s1_len + 1 + ft_strlen(s2);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, s1);
	new_str[s1_len] = glue;
	return (ft_strcat(new_str, s2));
}
