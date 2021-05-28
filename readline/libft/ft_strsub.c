/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:15:52 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:17:57 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (s == NULL)
		return (NULL);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	return (ft_strncpy(new_str, s + start, len));
}
