/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:27:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	print_newline(void)
{
	wrap_cursor();
	ft_putchar('\n');
	g_rl_state.current_line++;
	g_rl_state.cursor_line_pos = 0;
}
