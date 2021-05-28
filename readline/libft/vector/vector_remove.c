/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:39:20 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

int	vector_remove(t_vector *vector, size_t index)
{
	if (!vector || index >= vector->length || vector->length == 0)
		return (-1);
	if (vector->free_element)
		vector->free_element(vector->array + index * vector->element_size);
	if (vector->length >= 2 && index + 2 <= vector->length)
		ft_memmove(vector->array + index * vector->element_size,
			vector->array + (index + 1) * vector->element_size,
			(vector->length - index + 1) * vector->element_size);
	vector->length--;
	if (vector->length > 16 && vector->length <= vector->capacity / 4)
		vector_shrink(vector);
	return (0);
}
