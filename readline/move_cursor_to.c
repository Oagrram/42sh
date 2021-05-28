/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:33:04 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 12:56:07 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

static int	get_cursor_line_index(int line, int cursor_line_pos)
{
	int						index;
	int						i;
	t_readline_state *const	rl = &g_rl_state;

	i = 0;
	index = 0;
	if (i == 0 && i < line)
	{
		index += (rl->lines->array[i].len + rl->prompt_len) / rl->win_cols + 1;
		i++;
	}
	while (i < line)
		index += (rl->lines->array[i++].len / rl->win_cols) + 1;
	if (i == 0)
	{
		index += (cursor_line_pos + 1 + rl->prompt_len) / rl->win_cols;
		index += (cursor_line_pos + 1 + rl->prompt_len) % rl->win_cols != 0;
	}
	else
		index += ((cursor_line_pos + 1) / rl->win_cols)
			+ ((cursor_line_pos + 1) % rl->win_cols != 0);
	return (index);
}

static int	get_relative_column(int line, int cursor_line_pos)
{
	return (((cursor_line_pos
				+ ter_ul(line == 0, g_rl_state.prompt_len, 0))
			% g_rl_state.win_cols)
		- ((g_rl_state.cursor_line_pos
				+ ter_ul
				(g_rl_state.current_line == 0, g_rl_state.prompt_len, 0))
			% g_rl_state.win_cols));
}

static void	cursor_goto_relative(int rel_col, int rel_row)
{
	if (rel_col < 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, -rel_col), 1, ft_putchar);
	else if (rel_col > 0)
		tputs(tgoto(tgetstr("RI", NULL), 0, rel_col), 1, ft_putchar);
	if (rel_row < 0)
		tputs(tgoto(tgetstr("UP", NULL), 0, -rel_row), 1, ft_putchar);
	else if (rel_row > 0)
		tputs(tgoto(tgetstr("DO", NULL), 0, rel_row), 1, ft_putchar);
}

void	move_cursor_to(int line, int cursor_line_pos)
{
	int	relative_row;
	int	relative_column;

	relative_row = get_cursor_line_index(line, cursor_line_pos)
		- get_cursor_line_index(g_rl_state.current_line,
			g_rl_state.cursor_line_pos);
	relative_column = get_relative_column(line, cursor_line_pos);
	cursor_goto_relative(relative_column, relative_row);
	g_rl_state.current_line = line;
	g_rl_state.cursor_line_pos = cursor_line_pos;
}
