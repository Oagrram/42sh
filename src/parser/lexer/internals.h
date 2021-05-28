/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:14:47 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/29 14:19:09 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

typedef struct s_lexer
{
	t_vector		*tokens;
	t_string		*word;
	char			*line;
	t_stack			*quotes_stack;
	size_t			i;
	t_bool			backslash;
	t_bool			is_word_complete;
	char			c;

}				t_lexer;

int			lexer_is_operator(char c);
int			lexer_is_word(char c);
void		lexer_handle_operator(t_lexer *lex);
void		lexer_handle_io_number(t_lexer *lex);
void		lexer_handle_word(t_lexer *lex);
void		lexer_push_token(t_lexer *lex, t_token_type token_type);
void		lexer_push_token_assign(t_lexer *lex, size_t equal_index);
void		lexer_advance(t_lexer *lex, size_t by);
void		lexer_skip_whitespaces(t_lexer *lex);
int			lexer_operator_len(t_token_type type);
t_bool		lexer_is_word_complete(t_lexer *lex);

#endif
