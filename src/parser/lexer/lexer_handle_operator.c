/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:28 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 18:19:35 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_token_type	which_or_operator(t_lexer *lex)
{
	if (ft_strnequ(lex->line + lex->i, "||", 2))
		return (OROR);
	return (PIPE);
}

static t_token_type	which_and_operator(t_lexer *lex)
{
	if (ft_strnequ(lex->line + lex->i, "&&", 2))
		return (ANDAND);
	else if (ft_strnequ(lex->line + lex->i, "&>>", 3))
		return (ANDDGREAT);
	else if (ft_strnequ(lex->line + lex->i, "&>", 2))
		return (ANDGREAT);
	return (AMPERSAND);
}

static t_token_type	which_great_operator(t_lexer *lex)
{
	if (ft_strnequ(lex->line + lex->i, ">&-", 3))
		return (GREATANDDASH);
	else if (ft_strnequ(lex->line + lex->i, ">&", 2))
		return (GREATAND);
	else if (ft_strnequ(lex->line + lex->i, ">>", 2))
		return (DGREAT);
	return (GREAT);
}

static t_token_type	which_less_operator(t_lexer *lex)
{
	if (ft_strnequ(lex->line + lex->i, "<&-", 3))
		return (LESSANDDASH);
	else if (ft_strnequ(lex->line + lex->i, "<&", 2))
		return (LESSAND);
	else if (ft_strnequ(lex->line + lex->i, "<<", 2))
		return (DLESS);
	return (LESS);
}

void	lexer_handle_operator(t_lexer *lex)
{
	t_token_type	token_type;

	token_type = 0;
	if (lex->c == ';')
		token_type = SEMI;
	else if (lex->c == '|')
		token_type = which_or_operator(lex);
	else if (lex->c == '&')
		token_type = which_and_operator(lex);
	else if (lex->c == '>')
		token_type = which_great_operator(lex);
	else if (lex->c == '<')
		token_type = which_less_operator(lex);
	lexer_advance(lex, lexer_operator_len(token_type));
	lexer_push_token(lex, token_type);
}
