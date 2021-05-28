/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_previous_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:21:07 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 12:53:24 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_previous_word(void)
{
	t_readline_state *const	rl = &g_rl_state;
	int						i;
	int						j;

	j = rl->current_line;
	i = rl->cursor_line_pos - 1;
	if (i < 0)
		i = rl->lines->array[--j].len;
	while (j >= 0)
	{
		while (i >= 0 && !ft_isalnum(rl->lines->array[j].str[i]))
			i--;
		if (i >= 0 && ft_isalnum(rl->lines->array[j].str[i]))
			break ;
		j--;
		i = rl->lines->array[j].len - 1;
	}
	if (j < 0)
	{
		goto_home();
		return ;
	}
	while (i >= 0 && ft_isalnum(rl->lines->array[j].str[i]))
		i--;
	move_cursor_to(j, ter_i(i < 0, 0, i + 1));
}
