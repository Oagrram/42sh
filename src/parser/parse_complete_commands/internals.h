/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:26:41 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/21 10:45:40 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "../parse_simple_cmd/parse_simple_cmd.h"
# include "../parse_pipe/parse_pipe.h"
# include "../parse_and_or/parse_and_or.h"

typedef struct s_parse_complete
{
	t_vector	*commands;
	t_vector	*cmd_tokens;
	t_token		*tokens;
	t_token		current_token;
	size_t		tokens_index;
	size_t		tokens_len;
	t_cmd_type	cmd_type;
}				t_parse_complete;

int		add_complete_cmd(t_parse_complete *parser);
void	reset_cmd_tokens(t_parse_complete *parser);
void	push_cmd_token(t_parse_complete *parser);
void	unexpected_token(t_token_type type);
#endif
