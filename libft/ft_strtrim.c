/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:02:23 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 18:20:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s)
{
	size_t	start;

	start = 0;
	while (ft_isspace(s[start]))
		++start;
	return (start);
}

static size_t	get_end(char const *s, size_t start)
{
	size_t	end;

	end = ft_strlen(s) - 1;
	while (start < end && ft_isspace(s[end]))
		--end;
	++end;
	return (end);
}

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	start = get_start(s);
	end = get_end(s, start);
	new_str = (char *)ft_malloc(end - start + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
