/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:04:58 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/23 17:05:59 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

typedef struct s_read_multiline
{
	char			*line;
	char			*cmd_line;
	t_readline_ret	read_ret;
	t_lexer_ret		*lex_ret;
	char			*prompt;
}	t_read_multiline;

#endif
