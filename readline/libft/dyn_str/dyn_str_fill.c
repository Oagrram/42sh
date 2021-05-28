/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:54:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:17 by ylagtab          ###   ########.fr       */
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
	dyn_str->str = (char *)safe_malloc(initial_capacity * sizeof(char));
	dyn_str->len = 0;
	dyn_str->str[0] = '\0';
	return (dyn_str);
}
