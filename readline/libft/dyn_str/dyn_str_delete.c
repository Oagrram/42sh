/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:56:49 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/20 16:53:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_delete(t_dyn_str *dyn_str, size_t i, t_delete_mode delete_mode,
			size_t size)
{
	if (!dyn_str || i > dyn_str->len)
		return ;
	if (delete_mode == TO_END && i < dyn_str->len)
	{
		dyn_str->str[i] = '\0';
		dyn_str->len = i;
	}
	else if (delete_mode == TO_START)
	{
		ft_strcpy(dyn_str->str, dyn_str->str + i);
		dyn_str->len = ft_strlen(dyn_str->str);
	}
	else if (delete_mode == BY_SIZE && i + size <= dyn_str->len)
	{
		ft_strcpy(dyn_str->str + i, dyn_str->str + i + size);
		dyn_str->len -= size;
	}
	dyn_str_shrink(dyn_str);
}
