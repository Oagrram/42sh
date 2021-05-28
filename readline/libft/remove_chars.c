/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 09:42:47 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:16:16 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(char *str, char *counted_chars)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		i = 0;
		while (counted_chars[i] && *str != counted_chars[i])
			i++;
		if (*str == counted_chars[i])
			count++;
		str++;
	}
	return (count);
}

char	*remove_chars(char *str, char *removed_chrs)
{
	int		count;
	char	*result;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	count = count_chars(str, removed_chrs);
	result = safe_malloc(ft_strlen(str) - count + 1);
	if (result == NULL)
		return (NULL);
	while (str[k])
	{
		i = 0;
		while (removed_chrs[i] && str[k] != removed_chrs[i])
			i++;
		if (str[k] == removed_chrs[i])
			k++;
		else
			result[j++] = str[k++];
	}
	result[j] = '\0';
	free(str);
	return (result);
}
