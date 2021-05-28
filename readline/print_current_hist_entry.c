/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_hist_entry.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:31:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:20:46 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

static t_dynstr_vector	*get_current_hist_entry(void)
{
	if (g_history.current_entry == -1)
		return (g_history.stage);
	else if (g_history.entries->array[g_history.current_entry].is_dirty)
		return (g_history.entries->array[g_history.current_entry].temp);
	else
		return (g_history.entries->array[g_history.current_entry].entry);
}

void	print_current_hist_entry(void)
{
	t_readline_state *const	rl = &g_rl_state;
	size_t					i;

	i = 0;
	goto_home();
	rl->lines = get_current_hist_entry();
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	reprint_line();
	i++;
	while (i < rl->lines->length)
	{
		print_newline();
		reprint_line();
		i++;
	}
	wrap_cursor();
	rl->current_line = --i;
	rl->cursor_line_pos = rl->lines->array[i].len;
}
