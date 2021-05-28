/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_readline_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:34:23 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:26:54 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	init_readline_state(size_t prompt_len)
{
	t_dyn_str	line;

	update_win_dimensions();
	g_rl_state.prompt_len = prompt_len;
	g_rl_state.current_line = 0;
	g_rl_state.cursor_line_pos = 0;
	g_rl_state.lines = (void *)vector_init(sizeof(t_dyn_str), free_dyn_str);
	dyn_str_fill(&line, 0);
	vector_push((t_vector *)g_rl_state.lines, &line);
	if (g_rl_state.clipboard == NULL)
		g_rl_state.clipboard = dyn_str_create(0);
}
