/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_print_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:55:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 14:31:11 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*g_tokens_to_string[] = {
	[START] = "START",
	[WORD] = "WORD",
	[ASSIGNMENT] = "ASSIGNMENT",
	[IO_NUMBER] = "IO_NUMBER",
	[GREAT] = "GREAT",
	[ANDGREAT] = "ANDGREAT",
	[DGREAT] = "DGREAT",
	[ANDDGREAT] = "ANDDGREAT",
	[LESS] = "LESS",
	[DLESS] = "DLESS",
	[GREATAND] = "GREATAND",
	[LESSAND] = "LESSAND",
	[GREATANDDASH] = "GREATANDDASH",
	[LESSANDDASH] = "LESSANDDASH",
	[PIPE] = "PIPE",
	[OROR] = "OROR",
	[ANDAND] = "ANDAND",
	[SEMI] = "SEMI",
	[AMPERSAND] = "AMPERSAND",
	[NEWLINE] = "NEWLINE"
};

char	*g_tokens_to_symbol[] = {
	[START] = "START",
	[WORD] = "WORD",
	[ASSIGNMENT] = "ASSIGNMENT",
	[IO_NUMBER] = "IO_NUMBER",
	[GREAT] = ">",
	[ANDGREAT] = "&>",
	[DGREAT] = ">>",
	[ANDDGREAT] = "&>>",
	[LESS] = "<",
	[DLESS] = "<<",
	[GREATAND] = ">&",
	[LESSAND] = "<&",
	[GREATANDDASH] = ">&-",
	[LESSANDDASH] = "<&-",
	[PIPE] = "|",
	[OROR] = "||",
	[ANDAND] = "&&",
	[SEMI] = ";",
	[AMPERSAND] = "&",
	[NEWLINE] = "NEWLINE"
};

void	lexer_print_tokens(t_vector *tokens_vec)
{
	t_token	*tokens;
	t_token	tk;
	size_t	tokens_len;
	size_t	i;

	tokens = (t_token *)tokens_vec->array;
	tokens_len = tokens_vec->length;
	i = 0;
	while (i < tokens_len)
	{
		tk = tokens[i];
		printf("%s", g_tokens_to_string[tk.type]);
		if (tk.type == WORD || tk.type == IO_NUMBER)
			printf(" %s", (char *)tk.data);
		printf("\n");
		++i;
	}
}
