/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_prev_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:23:19 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:32:03 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	delete_prev_char(void)
{
	int	current_line;

	mark_hist_entry_as_dirty();
	if (g_rl_state.current_line == 0 && g_rl_state.cursor_line_pos == 0)
		return ;
	else if (g_rl_state.current_line > 0 && g_rl_state.cursor_line_pos == 0)
	{
		current_line = g_rl_state.current_line;
		move_cursor_to(current_line - 1,
			g_rl_state.lines->array[current_line - 1].len);
		merge_lines(current_line - 1, current_line);
	}
	else if (g_rl_state.cursor_line_pos > 0)
	{
		move_cursor_to(g_rl_state.current_line, g_rl_state.cursor_line_pos - 1);
		dyn_str_delete_chr(g_rl_state.lines->array + g_rl_state.current_line,
			g_rl_state.cursor_line_pos);
	}
	update_lines();
}
