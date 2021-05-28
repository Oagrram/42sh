/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:32:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/22 13:33:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	lexer_quote_type(char c)
{
	if (c == DOUBLE_QUOTE || c == SINGLE_QUOTE)
		return (c);
	return (0);
}

int	lexer_is_operator(char c)
{
	return (c == ';' || c == '&' || c == '|' || c == '<' || c == '>');
}

int	lexer_is_word(char c)
{
	return (!ft_isspace(c) && !lexer_is_operator(c));
}
