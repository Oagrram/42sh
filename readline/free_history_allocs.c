/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_history_allocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:12:57 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:31:37 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	free_history_allocs(void)
{
	t_history_state *const	hist = &g_history;
	t_readline_state *const	rl = &g_rl_state;

	if (hist->current_entry != -1
		&& rl->lines == hist->entries->array[hist->current_entry].temp)
	{
		vector_free((t_vector *)rl->lines);
		hist->entries->array[hist->current_entry].temp = NULL;
		hist->entries->array[hist->current_entry].is_dirty = 0;
	}
	vector_free((t_vector *)hist->stage);
}
