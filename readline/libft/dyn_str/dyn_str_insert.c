/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:49:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:34:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_insert(t_dyn_str *dyn_str, size_t i, char *str)
{
	size_t	inserted_str_len;

	if (!dyn_str || !str)
		return ;
	if (i >= dyn_str->len)
		i = dyn_str->len;
	inserted_str_len = ft_strlen(str);
	if (inserted_str_len + dyn_str->len + 1 >= dyn_str->capacity)
		dyn_str_expand(dyn_str, inserted_str_len + dyn_str->len + 1);
	ft_memmove(&dyn_str->str[i] + inserted_str_len, &dyn_str->str[i],
		dyn_str->len + 1 - i);
	ft_memcpy(&dyn_str->str[i], str, inserted_str_len);
	dyn_str->len += inserted_str_len;
}
