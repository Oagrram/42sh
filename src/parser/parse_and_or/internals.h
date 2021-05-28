/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:38:12 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/22 13:41:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "../parse_simple_cmd/parse_simple_cmd.h"
# include "../parse_pipe/parse_pipe.h"

typedef struct s_parse_and_or
{
	t_logic_sequence	*logic_cmd;
	t_vector			*cmd_tokens;
	t_token				*tokens;
	t_token				current_token;
	size_t				tokens_index;
	size_t				tokens_len;
	t_cmd_type			cmd_type;
}	t_parse_and_or;

void	unexpected_token(t_token_type type);
int		and_or_push_command(t_parse_and_or *and_or, t_bool is_last_cmd);

#endif
