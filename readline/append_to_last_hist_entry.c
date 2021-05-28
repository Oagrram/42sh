/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_last_hist_entry.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:51:36 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:33:00 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	append_to_last_hist_entry(char *partial_entry)
{
	t_dynstr_vector	*partial_entry_lines;
	t_dynstr_vector	*last_hist_entry;

	if (g_history.entries->length == 0)
		return ;
	last_hist_entry
		= g_history.entries->array[g_history.entries->length - 1].entry;
	partial_entry_lines = str_to_dynstr_vec(partial_entry);
	vector_insert_all((void *)last_hist_entry, (void *)partial_entry_lines,
		g_history.entries->length - 1);
	partial_entry_lines->free_element = NULL;
	vector_free((void *)partial_entry_lines);
}
