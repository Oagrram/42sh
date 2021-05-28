/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_hist_entry_as_dirty.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:59 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:25:38 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	mark_hist_entry_as_dirty(void)
{
	t_history_state *const	hist = &g_history;

	if (hist->entries->length > 0
		&& hist->current_entry != -1
		&& hist->entries->array[hist->current_entry].is_dirty == FALSE)
	{
		hist->entries->array[hist->current_entry].is_dirty = TRUE;
		hist->entries->array[hist->current_entry].temp = clone_dynstr_vector(
				hist->entries->array[hist->current_entry].entry);
		g_rl_state.lines = hist->entries->array[hist->current_entry].temp;
	}
}
