/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_previous_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:09:22 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:29:28 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_previous_line(void)
{
	t_readline_state *const	rl = &g_rl_state;

	if (rl->current_line > 0)
	{
		if (rl->cursor_line_pos <= rl->lines->array[rl->current_line - 1].len)
			move_cursor_to(rl->current_line - 1, rl->cursor_line_pos);
		else
			move_cursor_to(rl->current_line - 1,
				rl->lines->array[rl->current_line - 1].len);
	}
}
