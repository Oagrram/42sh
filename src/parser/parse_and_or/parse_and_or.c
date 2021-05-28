/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:01:31 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 15:57:25 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_and_or	*and_or_init(t_vector *tokens_vec)
{
	t_parse_and_or	*and_or;

	and_or = (t_parse_and_or *)ft_malloc(sizeof(t_parse_and_or));
	and_or->logic_cmd = (t_logic_sequence *)ft_malloc(sizeof(t_logic_sequence));
	and_or->logic_cmd->commands = vector_init(sizeof(t_command), free_command);
	and_or->logic_cmd->logic_ops = vector_init(sizeof(t_token_type), NULL);
	and_or->cmd_tokens = vector_init(sizeof(t_token), free);
	and_or->cmd_type = SIMPLE_CMD;
	and_or->tokens = (t_token *)tokens_vec->array;
	and_or->tokens_len = tokens_vec->length;
	and_or->tokens_index = 0;
	and_or->current_token = and_or->tokens[and_or->tokens_index];
	return (and_or);
}

static void	and_or_advance(t_parse_and_or *and_or)
{
	++(and_or->tokens_index);
	and_or->current_token = and_or->tokens[and_or->tokens_index];
}

static void	push_cmd_token(t_parse_and_or *parser)
{
	vector_push(parser->cmd_tokens, &(parser->current_token));
	if (parser->current_token.type == PIPE)
		parser->cmd_type = PIPE_SEQ;
}

static void	*and_or_clean(t_parse_and_or *and_or)
{
	vector_free(and_or->cmd_tokens);
	free(and_or);
	return (NULL);
}

t_logic_sequence	*parse_and_or(t_vector *tokens_vec)
{
	t_parse_and_or		*and_or;
	t_logic_sequence	*logic_cmd;

	and_or = and_or_init(tokens_vec);
	while (and_or->tokens_index < and_or->tokens_len)
	{
		if (lexer_is_and_or(and_or->current_token.type))
		{
			if (and_or_push_command(and_or, FALSE) == EXIT_FAILURE)
				return (and_or_clean(and_or));
			vector_push(and_or->logic_cmd->logic_ops,
				&(and_or->current_token.type));
		}
		else
			push_cmd_token(and_or);
		and_or_advance(and_or);
	}
	if (and_or_push_command(and_or, TRUE) == EXIT_FAILURE)
		return (NULL);
	logic_cmd = and_or->logic_cmd;
	logic_cmd->job_name = get_job_name(tokens_vec);
	(void)and_or_clean(and_or);
	return (logic_cmd);
}
