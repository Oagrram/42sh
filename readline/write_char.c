/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:01:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	write_char(char c)
{
	t_readline_state *const	rl = &g_rl_state;

	mark_hist_entry_as_dirty();
	dyn_str_insert_chr(rl->lines->array + rl->current_line,
		rl->cursor_line_pos, c);
	ft_putchar(c);
	rl->cursor_line_pos++;
	update_lines();
}
