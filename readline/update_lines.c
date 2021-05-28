/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:35:08 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:32:53 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	update_lines(void)
{
	size_t	i;
	int		orig_curr_line;
	int		orig_cursor_pos;

	i = g_rl_state.current_line;
	orig_curr_line = g_rl_state.current_line;
	orig_cursor_pos = g_rl_state.cursor_line_pos;
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	reprint_line();
	i++;
	while (i < g_rl_state.lines->length)
	{
		print_newline();
		reprint_line();
		i++;
	}
	wrap_cursor();
	move_cursor_to(orig_curr_line, orig_cursor_pos);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
}
