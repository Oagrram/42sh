/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:03:29 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:09:52 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	reprint_line(void)
{
	t_readline_state *const	rl = &g_rl_state;

	rl->cursor_line_pos += ft_putstr(rl->lines->array[rl->current_line].str
			+ rl->cursor_line_pos);
}
