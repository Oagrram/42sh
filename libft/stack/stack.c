/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:43:43 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/15 12:51:58 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack	*stack_new(size_t element_size,
	void (*free_element)(void *element))
{
	t_vector	*vec;

	vec = vector_init(element_size, free_element);
	return (vec);
}

void	stack_push(t_stack *stack, void *element)
{
	vector_push(stack, element);
}

void	*stack_pop(t_stack *stack)
{
	void	*element_to_pop;
	void	*el;

	el = ft_malloc(stack->element_size);
	element_to_pop = stack->array + (stack->length - 1) * stack->element_size;
	ft_memcpy(el, element_to_pop, stack->element_size);
	ft_bzero(element_to_pop, stack->element_size);
	--(stack->length);
	if (stack->length > 16 && stack->length <= stack->capacity / 4)
		vector_shrink(stack);
	return (el);
}

void	*stack_peek(t_stack *stack)
{
	if (stack->length == 0)
		return (NULL);
	return (stack->array + (stack->length - 1) * stack->element_size);
}
