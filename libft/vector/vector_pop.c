/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:39:00 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

int	vector_pop(t_vector *vector, void *element)
{
	if (!vector || !element || vector->length == 0)
		return (-1);
	ft_memcpy(element,
		vector->array + (vector->length - 1) * vector->element_size,
		vector->element_size);
	vector->length--;
	if (vector->length > 16 && vector->length <= vector->capacity / 4)
		vector_shrink(vector);
	return (0);
}
