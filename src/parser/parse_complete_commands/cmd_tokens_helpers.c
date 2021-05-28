/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokens_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:42:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/20 16:22:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	set_cmd_type(t_parse_complete *parser)
{
	t_token_type	token_type;

	token_type = parser->current_token.type;
	if (parser->cmd_type == LOGIC_SEQ)
		return ;
	if (token_type == ANDAND || token_type == OROR)
		parser->cmd_type = LOGIC_SEQ;
	if (token_type == PIPE)
		parser->cmd_type = PIPE_SEQ;
}

void	reset_cmd_tokens(t_parse_complete *parser)
{
	vector_free(parser->cmd_tokens);
	parser->cmd_tokens = vector_init(sizeof(t_token), NULL);
}

void	push_cmd_token(t_parse_complete *parser)
{
	vector_push(parser->cmd_tokens, &(parser->current_token));
	set_cmd_type(parser);
}
