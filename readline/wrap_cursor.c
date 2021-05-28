/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:52:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:07:23 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	wrap_cursor(void)
{
	t_readline_state *const	rl = &g_rl_state;
	int						x;

	if (rl->current_line == 0)
		x = rl->cursor_line_pos + rl->prompt_len;
	else
		x = rl->cursor_line_pos + 0;
	if (x % rl->win_cols == 0)
	{
		ft_putchar(' ');
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	}
}
