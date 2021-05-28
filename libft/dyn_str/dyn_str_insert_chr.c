/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_insert_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:53:15 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/23 22:37:43 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_insert_chr(t_dyn_str *dyn_str, size_t i, char c)
{
	if (dyn_str->len + 2 >= dyn_str->capacity)
		dyn_str_expand(dyn_str, dyn_str->len + 2);
	if (i >= dyn_str->len)
		i = dyn_str->len;
	ft_memmove(dyn_str->str + i + 1, dyn_str->str + i, dyn_str->len + 1 - i);
	dyn_str->str[i] = c;
	dyn_str->len++;
}
