/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:05:08 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:35:47 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** find `c` index in `s`, otherwise return -1
*/

size_t	ft_strichr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		else
			i++;
	}
	return (-1);
}
