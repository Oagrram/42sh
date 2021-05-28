/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:39:28 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 14:02:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef t_vector	t_stack;

t_stack				*stack_new(size_t element_size,
						void (*free_element)(void *element));
void				stack_push(t_stack *stack, void *element);
void				*stack_pop(t_stack *stack);
void				*stack_peek(t_stack *stack);

#endif
