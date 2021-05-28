/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:36:50 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/24 13:21:30 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	unexpected_token(t_token_type type)
{
	ft_printf(2, "42sh: syntax error near unexpected token `%s'\n",
		g_tokens_to_symbol[type]);
}

void	unmatch_quote_error(char unmatched_char)
{
	char	matched_char;

	matched_char = '\0';
	if (unmatched_char == '(')
		matched_char = ')';
	else if (unmatched_char == ')')
		matched_char = '(';
	else if (unmatched_char == '{')
		matched_char = '}';
	else if (unmatched_char == '}')
		matched_char = '{';
	else if (unmatched_char == DOUBLE_QUOTE || unmatched_char == SINGLE_QUOTE)
		matched_char = unmatched_char;
	ft_printf(2, "42h: unexpected EOF while looking for matching `%c`\n",
		matched_char);
}
