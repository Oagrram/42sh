/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:47:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 16:03:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (k != i)
			count++;
	}
	return (count);
}

static char	**create_table(const char *s, char c)
{
	char	**t;
	int		w_count;

	w_count = count_words((char *)s, c) + 1;
	t = (char **)ft_malloc(w_count * sizeof(char *));
	return (t);
}

static void	free_table(char **words, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	add_word(char **words, char const *s, int len, int j)
{
	words[j] = ft_strsub(s, 0, len);
	if (words[j] == NULL)
	{
		free_table(words, j);
		return (1);
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**words;

	if (s != NULL)
		words = create_table(s, c);
	if (s == NULL || words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i && add_word(words, s + start, i - start, j++))
			return (NULL);
	}
	words[j] = NULL;
	return (words);
}
