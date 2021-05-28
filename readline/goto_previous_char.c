/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_previous_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:09:58 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:29:52 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_previous_char(void)
{
	if (g_rl_state.current_line == 0 && g_rl_state.cursor_line_pos == 0)
		return ;
	else if (g_rl_state.cursor_line_pos == 0
		&& g_rl_state.current_line > 0)
	{
		move_cursor_to(g_rl_state.current_line - 1,
			g_rl_state.lines->array[g_rl_state.current_line - 1].len);
	}
	else
		move_cursor_to(g_rl_state.current_line, g_rl_state.cursor_line_pos - 1);
}
