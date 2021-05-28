/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_next_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:14:44 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:30:08 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_next_word(void)
{
	t_readline_state *const	rl = &g_rl_state;
	size_t					i;
	size_t					j;

	i = rl->cursor_line_pos;
	j = rl->current_line;
	while (j < rl->lines->length)
	{
		while (rl->lines->array[j].str[i]
			&& !ft_isalnum(rl->lines->array[j].str[i]))
			i++;
		if (ft_isalnum(rl->lines->array[j].str[i]))
			break ;
		j++;
		i = 0;
	}
	if (j == rl->lines->length)
	{
		goto_end();
		return ;
	}
	while (ft_isalnum(rl->lines->array[j].str[i]))
		i++;
	move_cursor_to(j, i);
}
