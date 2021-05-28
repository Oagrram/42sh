/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynstr_vector_equ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:33:23 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

int	dynstr_vector_equ(t_dynstr_vector *dynstr_vec1,
		t_dynstr_vector *dynstr_vec2)
{
	size_t	i;

	if (dynstr_vec1 == NULL || dynstr_vec2 == NULL)
		return (0);
	if (dynstr_vec1->length != dynstr_vec2->length)
		return (0);
	i = 0;
	while (i < dynstr_vec1->length)
	{
		if (!ft_strequ(dynstr_vec1->array[i].str, dynstr_vec2->array[i].str))
			return (0);
		i++;
	}
	return (1);
}
