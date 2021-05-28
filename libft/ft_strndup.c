/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:28:58 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:04:02 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new_str;

	new_str = ft_strnew(n);
	if (s == NULL || new_str == NULL)
		return (NULL);
	return (ft_strncpy(new_str, s, n));
}
