/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:22:52 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/06 15:32:53 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

void	*vector_get(t_vector *vector, size_t index)
{
	if (!vector || index >= vector->length)
		return (NULL);
	return (vector->array + index * vector->element_size);
}
