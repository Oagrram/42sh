/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:33:31 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:27:04 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	init_history_state(void)
{
	if (g_history.entries == NULL)
		g_history.entries = (void *)vector_init(sizeof(t_hist_entry), NULL);
	g_history.current_entry = -1;
	g_history.stage = g_rl_state.lines;
}
