/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:10:55 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 15:48:26 by ylagtab          ###   ########.fr       */
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
