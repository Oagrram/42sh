/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/03 12:48:33 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

void	vector_free(t_vector *vector)
{
	size_t	i;

	if (vector == NULL)
		return ;
	if (vector->free_element)
	{
		i = 0;
		while (i < vector->length)
			vector->free_element(vector->array + vector->element_size * i++);
	}
	free(vector->array);
	free(vector);
}
