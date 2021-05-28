/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_control_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:17:42 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:27:56 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	handle_control_chars(char c)
{
	if (c == 127)
		delete_prev_char();
	else if (c == 11)
		kill_cursor_to_end();
	else if (c == 25)
		yank_clipboard();
	else if (c == 4
		&& (g_rl_state.lines->array[0].len > 0
			|| g_rl_state.lines->length > 1))
		delete_next_char();
}
