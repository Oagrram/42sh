/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:26:17 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:31:25 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dyn_str_internal.h"

void	dyn_str_expand(t_dyn_str *dyn_str, size_t new_len)
{
	size_t	new_capacity;
	char	*new_str;

	new_capacity = get_close_power_of_2(new_len);
	new_str = (char *)ft_malloc(new_capacity * sizeof(char));
	dyn_str->capacity = new_capacity;
	ft_strcpy(new_str, dyn_str->str);
	free(dyn_str->str);
	dyn_str->str = new_str;
}
