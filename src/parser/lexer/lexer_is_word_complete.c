/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_word_complete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:51:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 18:58:32 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_bool	lexer_is_word_complete(t_lexer *lex)
{
	return (lex->quotes_stack->length == 0 && lex->backslash == FALSE);
}
