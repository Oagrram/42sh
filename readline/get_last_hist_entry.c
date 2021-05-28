/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_hist_entry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:15:24 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:31:04 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

char	*get_last_hist_entry(void)
{
	t_dynstr_vector	*last_hist_entry;

	if (g_history.entries->length == 0)
		return (NULL);
	last_hist_entry
		= g_history.entries->array[g_history.entries->length - 1].entry;
	return (dynstr_vec_to_str(last_hist_entry));
}
