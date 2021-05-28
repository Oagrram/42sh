/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 06:36:02 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:15:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_until_chars(char *str, char *stop_chars)
{
	int	i;

	if (!str || !stop_chars)
		return (NULL);
	while (*str)
	{
		i = 0;
		while (stop_chars[i] && *str != stop_chars[i])
			i++;
		if (*str == stop_chars[i])
			break ;
		str++;
	}
	return (str);
}
