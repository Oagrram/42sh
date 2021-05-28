/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 06:50:05 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:15:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_chars(char *str, char *skipped_chars)
{
	int	i;

	if (!str || !skipped_chars)
		return (NULL);
	while (*str)
	{
		i = 0;
		while (skipped_chars[i] && *str != skipped_chars[i])
			i++;
		if (*str == skipped_chars[i])
			str++;
		else
			break ;
	}
	return (str);
}
