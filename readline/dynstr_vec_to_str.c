/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynstr_vec_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:58:24 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

char	*dynstr_vec_to_str(t_dynstr_vector *dynstr_vec)
{
	size_t		i;
	char		*ret_str;
	t_dyn_str	*dynstr;

	if (dynstr_vec == NULL)
		return (NULL);
	dynstr = dyn_str_create(16);
	i = 0;
	while (i < dynstr_vec->length)
	{
		if (i != 0)
			dyn_str_append_chr(dynstr, '\n');
		dyn_str_append(dynstr, dynstr_vec->array[i].str);
		i++;
	}
	ret_str = dynstr->str;
	free(dynstr);
	return (ret_str);
}
