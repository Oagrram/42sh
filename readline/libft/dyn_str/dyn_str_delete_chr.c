/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_delete_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:01:42 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:25:01 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_delete_chr(t_dyn_str *dyn_str, size_t i)
{
	if (i > dyn_str->len - 1)
		return ;
	if (dyn_str->len + 1 <= dyn_str->capacity / 4)
		dyn_str_shrink(dyn_str);
	ft_strcpy(dyn_str->str + i, dyn_str->str + i + 1);
	dyn_str->len--;
}
