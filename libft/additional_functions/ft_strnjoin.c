/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:08:42 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 14:08:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*get_strings_lengths(char **strings, int n, size_t *size)
{
	int		*lengths;
	int		i;

	*size = 0;
	i = 0;
	lengths = (int *)ft_malloc(sizeof(int));
	while (i < n)
	{
		if (!strings[i])
		{
			free(lengths);
			return (NULL);
		}
		lengths[i] = ft_strlen(strings[i]);
		*size += lengths[i];
		++i;
	}
	return (lengths);
}

char	*ft_strnjoin(char **strings, int n)
{
	char	*concat;
	size_t	size;
	int		i;
	int		*lengths;

	lengths = get_strings_lengths(strings, n, &size);
	concat = ft_strnew(size);
	if (concat)
	{
		i = 0;
		size = 0;
		while (i < n)
		{
			ft_strcat(concat + size, strings[i]);
			size += lengths[i];
			++i;
		}
	}
	free(lengths);
	return (concat);
}
