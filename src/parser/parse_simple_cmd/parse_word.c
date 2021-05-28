/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:28:50 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 15:23:14 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

/*
**static void		update_quoting(char c, char *quote, t_bool *backslash)
**{
**	if (*quote == SINGLE_QUOTE && c == SINGLE_QUOTE)
**		*quote = 0;
**	else if (*quote == DOUBLE_QUOTE && c == DOUBLE_QUOTE)
**	{
**		if (*backslash == FALSE)
**			*quote = 0;
**	}
**	else if (*quote == 0 && *backslash == FALSE)
**		*quote = lexer_quote_type(c);
**	if (*backslash)
**		*backslash = FALSE;
**	else
**		*backslash = c == BACK_SLASH && *quote != SINGLE_QUOTE;
**}
*/

static size_t	find_assignment_equal(char *word)
{
	size_t	i;
	size_t	equal_index;

	i = 0;
	equal_index = 0;
	while (word[i] && !is_quote(word[i]))
	{
		if (word[i] == '=')
		{
			equal_index = i;
			break ;
		}
		++i;
	}
	if (is_quote(word[i]))
		return (0);
	return (equal_index);
}

void	parse_word(t_parse_simple *sim)
{
	char	*word;
	size_t	equal_index;

	word = sim->current_token.data;
	equal_index = find_assignment_equal(word);
	if (equal_index > 0 && sim->is_done_assigning == FALSE)
		parse_assignment(sim, word, equal_index);
	else
		parse_argument(sim);
}
