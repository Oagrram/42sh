/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_io_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:59:40 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/21 19:04:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_handle_io_number(t_lexer *lex)
{
	while (lex->c && ft_isdigit(lex->c))
	{
		string_push(lex->word, lex->c);
		lexer_advance(lex, 1);
	}
	if (lex->c == '>' || lex->c == '<')
		lexer_push_token(lex, IO_NUMBER);
}
