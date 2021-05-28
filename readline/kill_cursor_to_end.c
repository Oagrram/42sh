/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cursor_to_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:15:20 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:26:29 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	kill_cursor_to_end(void)
{
	t_readline_state *const	rl = &g_rl_state;
	t_dyn_str *const		clipboard = rl->clipboard;
	size_t					i;

	mark_hist_entry_as_dirty();
	i = rl->current_line;
	dyn_str_delete(clipboard, 0, TO_END, 0);
	dyn_str_append(clipboard, rl->lines->array[i].str + rl->cursor_line_pos);
	dyn_str_delete(rl->lines->array + i, rl->cursor_line_pos, TO_END, 0);
	i++;
	while (i < rl->lines->length)
	{
		dyn_str_append_chr(clipboard, '\n');
		dyn_str_append(clipboard, rl->lines->array[i].str);
		vector_remove((t_vector *)rl->lines, i);
	}
	update_lines();
}
