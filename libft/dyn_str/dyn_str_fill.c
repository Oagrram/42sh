/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:54:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:31:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

t_dyn_str	*dyn_str_fill(t_dyn_str *dyn_str, size_t initial_capacity)
{
	if (dyn_str == NULL)
		return (NULL);
	if (initial_capacity == 0)
		initial_capacity = 16;
	dyn_str->capacity = initial_capacity;
	dyn_str->str = (char *)ft_malloc(initial_capacity * sizeof(char));
	dyn_str->len = 0;
	dyn_str->str[0] = '\0';
	return (dyn_str);
}
