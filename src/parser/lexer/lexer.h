/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:53:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 12:13:45 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

extern char	*g_tokens_to_string[];
extern char	*g_tokens_to_symbol[];

typedef struct s_lexer_ret
{
	t_vector	*tokens;
	t_bool		is_matched;
	char		unmatched_char;

}	t_lexer_ret;

t_lexer_ret	*lexer(char *line);
void		lexer_print_tokens(t_vector *tokens_vec);
void		lexer_add_newline_token(t_vector *tokens);
t_bool		lexer_is_redirection(t_token_type type);
t_bool		lexer_is_separator(t_token_type type);
t_bool		lexer_is_and_or(t_token_type type);
char		lexer_quote_type(char c);
t_token		*token_dup(t_token token);
t_string	*string_new(void);
void		string_free(t_string *str);
void		string_push(t_string *str, char c);
char		*string_get_data(t_string *str);
#endif
