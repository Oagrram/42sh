/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_shrink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:12:50 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:31:34 by mel-idri         ###   ########.fr       */
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
	new_str = (char *)ft_malloc((new_capacity) * sizeof(char));
	dyn_str->capacity = new_capacity;
	ft_strcpy(new_str, dyn_str->str);
	free(dyn_str->str);
	dyn_str->str = new_str;
}
