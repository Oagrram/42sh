/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 12:39:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	is_single_or_double_quote(char c)
{
	if (c == DOUBLE_QUOTE || c == SINGLE_QUOTE)
		return (c);
	return (0);
}

void	fill_str(char **word, t_remove_quotes *rq)
{
	rq->backslash = !rq->backslash && **word == BACK_SLASH
		&& rq->quote != SINGLE_QUOTE;
	if (rq->backslash == FALSE)
		string_push(rq->str, **word);
	++(*word);
}

char	*remove_quotes_from_word(char *word)
{
	t_remove_quotes	rq;
	char			*str;

	ft_bzero(&rq, sizeof(t_remove_quotes));
	rq.str = string_new();
	while (*word)
	{
		rq.quote = is_single_or_double_quote(*word);
		if (rq.quote)
		{
			++word;
			while (*word != rq.quote || rq.backslash)
				fill_str(&word, &rq);
			++word;
		}
		else
			while (*word && (!is_single_or_double_quote(*word) || rq.backslash))
				fill_str(&word, &rq);
	}
	str = string_get_data(rq.str);
	string_free(rq.str);
	return (str);
}

void	remove_quotes_from_args(char **args)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (args[i] != NULL)
	{
		tmp = remove_quotes_from_word(args[i]);
		free(args[i]);
		args[i] = tmp;
		++i;
	}
}
