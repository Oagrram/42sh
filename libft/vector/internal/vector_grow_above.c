/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_grow_above.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:25:05 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/19 11:00:53 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	vector_grow_above(t_vector *vector, size_t min_capacity)
{
	size_t	new_capacity;
	void	*new_array;

	new_capacity = 1;
	while (min_capacity)
	{
		min_capacity >>= 1;
		new_capacity <<= 1;
	}
	if (new_capacity > vector->capacity)
	{
		new_array = ft_malloc(new_capacity * vector->element_size);
		ft_memcpy(new_array, vector->array,
			vector->length * vector->element_size);
		free(vector->array);
		vector->array = new_array;
		vector->capacity = new_capacity;
	}
}
