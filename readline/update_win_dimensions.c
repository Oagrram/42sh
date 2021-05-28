/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_win_dimensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:15:21 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	update_win_dimensions(void)
{
	struct winsize	win_size;

	if (ioctl(0, TIOCGWINSZ, &win_size) == -1)
		exit_error("ioctl: error while retrieving window size");
	g_rl_state.win_cols = win_size.ws_col;
	g_rl_state.win_rows = win_size.ws_row;
}
