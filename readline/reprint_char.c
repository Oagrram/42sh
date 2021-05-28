/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:48:44 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:10:12 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

int	reprint_char(void)
{
	t_readline_state *const	rl = &g_rl_state;
	int						ret;

	ret = ft_putchar(rl->lines->array[rl->current_line]
			.str[rl->cursor_line_pos]);
	rl->cursor_line_pos++;
	return (ret);
}
