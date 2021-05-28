/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank_clipboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:09:04 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:46:58 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

static void	insert_lines(char **lines, char *line_remainder)
{
	t_readline_state *const	rl = &g_rl_state;
	t_dyn_str				line;
	int						i;

	mark_hist_entry_as_dirty();
	i = 1;
	while (lines[i])
	{
		dyn_str_dup(&line, lines[i]);
		vector_insert((t_vector *)rl->lines, &line, rl->current_line + 1 + i);
		i++;
	}
	rl->current_line += --i;
	dyn_str_append(rl->lines->array + rl->current_line, line_remainder);
	rl->cursor_line_pos = rl->lines->array[rl->current_line].len
		- ft_strlen(line_remainder);
}

void	yank_clipboard(void)
{
	t_readline_state *const	rl = &g_rl_state;
	char					**lines;
	char					*line_remainder;

	lines = ft_strsplit2(rl->clipboard->str, '\n', ALLOW_EMPTY_WORD);
	line_remainder = ft_strdup(rl->lines->array[rl->current_line].str
			+ rl->cursor_line_pos);
	dyn_str_delete(rl->lines->array + rl->current_line, rl->cursor_line_pos,
		TO_END, 0);
	dyn_str_append(rl->lines->array + rl->current_line, lines[0]);
	insert_lines(lines, line_remainder);
	free(line_remainder);
	ft_free_2d_chr_array(lines);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	ft_putstr(rl->clipboard->str);
	update_lines();
}
