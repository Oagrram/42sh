/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_grow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:32:59 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:49:53 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	vector_grow(t_vector *vector)
{
	void	*new_array;

	new_array = safe_malloc(vector->capacity * vector->element_size * 2);
	ft_memcpy(new_array, vector->array, vector->length * vector->element_size);
	free(vector->array);
	vector->array = new_array;
	vector->capacity *= 2;
}
