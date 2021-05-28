/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_push_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:01:45 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 18:22:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_push_token(t_lexer *lex, t_token_type token_type)
{
	t_token	token;

	if (token_type == WORD || token_type == IO_NUMBER)
		token.data = string_get_data(lex->word);
	else
		token.data = NULL;
	token.type = token_type;
	lex->word->length = 0;
	vector_push(lex->tokens, &token);
}

void	lexer_push_token_assign(t_lexer *lex, size_t equal_index)
{
	t_token	token;
	t_var	*var;

	var = (t_var *)ft_malloc(sizeof(t_var));
	var->key = ft_strsub(lex->word->data, 0, equal_index);
	var->value = ft_strsub(lex->word->data, equal_index + 1, lex->word->length);
	token.type = ASSIGNMENT;
	token.data = var;
	lex->word->length = 0;
	vector_push(lex->tokens, &token);
}
