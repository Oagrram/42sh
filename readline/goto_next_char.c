/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_next_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:22:36 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:30:49 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_next_char(void)
{
	if (g_rl_state.current_line + 1 == g_rl_state.lines->length
		&& g_rl_state.cursor_line_pos
		== g_rl_state.lines->array[g_rl_state.current_line].len)
		return ;
	else if (g_rl_state.cursor_line_pos
		== g_rl_state.lines->array[g_rl_state.current_line].len)
	{
		move_cursor_to(g_rl_state.current_line + 1, 0);
	}
	else
		move_cursor_to(g_rl_state.current_line, g_rl_state.cursor_line_pos + 1);
}
