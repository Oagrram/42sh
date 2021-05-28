/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:10:55 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 13:36:44 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(const char **s)
{
	char	*str;

	if (s == NULL || *s == NULL)
		return (NULL);
	str = ft_strdup(*s);
	ft_strdel((char **)s);
	return (str);
}
