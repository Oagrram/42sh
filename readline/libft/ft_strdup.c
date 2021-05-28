/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:44:28 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:39:21 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = (char *)safe_malloc(ft_strlen(s1) + 1);
	if (s == NULL)
		return (NULL);
	return (ft_strcpy(s, s1));
}
