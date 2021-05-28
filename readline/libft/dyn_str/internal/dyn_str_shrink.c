/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_shrink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:12:50 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dyn_str_internal.h"

void	dyn_str_shrink(t_dyn_str *dyn_str)
{
	char	*new_str;
	size_t	new_capacity;

	if (dyn_str->len + 1 > dyn_str->capacity / 4)
		return ;
	if (dyn_str->capacity / 4 < 16)
		new_capacity = 16;
	else
		new_capacity = dyn_str->capacity / 4;
	new_str = (char *)safe_malloc((new_capacity) * sizeof(char));
	dyn_str->capacity = new_capacity;
	ft_strcpy(new_str, dyn_str->str);
	free(dyn_str->str);
	dyn_str->str = new_str;
}
