/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_skip_whitespaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:12:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 09:36:46 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_skip_whitespaces(t_lexer *lex)
{
	while (ft_isspace(lex->c))
		lexer_advance(lex, 1);
}
