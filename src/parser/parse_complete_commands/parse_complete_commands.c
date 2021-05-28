/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_complete_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:42:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 15:40:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_complete	*parser_init(t_vector *tokens)
{
	t_parse_complete	*parser;

	parser = (t_parse_complete *)ft_malloc(sizeof(t_parse_complete));
	parser->commands = vector_init(sizeof(t_command), free_command);
	parser->cmd_tokens = vector_init(sizeof(t_token), NULL);
	parser->cmd_type = SIMPLE_CMD;
	parser->tokens = (t_token *)tokens->array;
	parser->tokens_len = tokens->length;
	parser->tokens_index = 0;
	parser->current_token = parser->tokens[parser->tokens_index];
	return (parser);
}

static void	parser_clean(t_parse_complete *parser)
{
	vector_free(parser->cmd_tokens);
	ft_bzero(parser, sizeof(t_parse_complete));
	free(parser);
}

static void	*parser_free_all(t_parse_complete *parser)
{
	vector_free(parser->commands);
	parser_clean(parser);
	return (NULL);
}

void	parser_advance(t_parse_complete *parser)
{
	if (parser->tokens_index > parser->tokens_len - 1)
		return ;
	++(parser->tokens_index);
	parser->current_token = parser->tokens[parser->tokens_index];
}

t_vector	*parse_complete_commands(t_vector *tokens)
{
	t_parse_complete	*parser;
	t_vector			*commands;

	parser = parser_init(tokens);
	if (parser->tokens_len > 1 || parser->current_token.type != NEWLINE)
	{
		while (parser->tokens_index < parser->tokens_len)
		{
			if (lexer_is_separator(parser->current_token.type))
			{
				if (add_complete_cmd(parser) == EXIT_FAILURE)
					return (parser_free_all(parser));
			}
			else
				push_cmd_token(parser);
			parser_advance(parser);
		}
	}
	commands = parser->commands;
	parser_clean(parser);
	return (commands);
}
