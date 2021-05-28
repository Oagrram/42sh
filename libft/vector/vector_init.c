/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:32:59 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:37:47 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

t_vector	*vector_init(size_t element_size,
		void (*free_element)(void *element))
{
	t_vector	*vec;

	vec = ft_malloc(sizeof(t_vector));
	vec->array = ft_malloc(element_size * 16);
	vec->capacity = 16;
	vec->element_size = element_size;
	vec->length = 0;
	vec->free_element = free_element;
	return (vec);
}

t_vector	*vector_init_capacity(size_t element_size, size_t min_capacity,
		void (*free_element)(void *element))
{
	t_vector	*vec;
	size_t		capacity;

	capacity = 1;
	while (min_capacity)
	{
		min_capacity >>= 1;
		capacity <<= 1;
	}
	vec = ft_malloc(sizeof(t_vector));
	vec->capacity = capacity;
	vec->array = ft_malloc(element_size * vec->capacity);
	vec->element_size = element_size;
	vec->length = 0;
	vec->free_element = free_element;
	return (vec);
}
