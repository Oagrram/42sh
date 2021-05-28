/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hist_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:08:18 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:33:18 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	add_hist_entry(char *entry_str)
{
	t_hist_entry	hist_entry;

	hist_entry.temp = NULL;
	hist_entry.is_dirty = FALSE;
	hist_entry.entry = str_to_dynstr_vec(entry_str);
	vector_push((void *)g_history.entries, &hist_entry);
}
