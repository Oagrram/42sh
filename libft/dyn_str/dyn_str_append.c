/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:40:56 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:13:06 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_append(t_dyn_str *dyn_str, char *str)
{
	size_t	new_str_len;

	if (!dyn_str || !str)
		return ;
	new_str_len = dyn_str->len + ft_strlen(str);
	if (new_str_len + 1 >= dyn_str->capacity)
		dyn_str_expand(dyn_str, new_str_len + 1);
	ft_strcat(dyn_str->str + dyn_str->len, str);
	dyn_str->len = new_str_len;
}
