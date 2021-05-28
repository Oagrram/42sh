/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 02:25:05 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:29:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INTERNAL_H
# define VECTOR_INTERNAL_H
# include "../../libft.h"
# include "../vector.h"

void	vector_grow(t_vector *vector);
void	vector_shrink(t_vector *vector);
void	vector_grow_above(t_vector *vector, size_t min_capacity);

#endif
