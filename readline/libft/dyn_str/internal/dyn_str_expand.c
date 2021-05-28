/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:26:17 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dyn_str_internal.h"

void	dyn_str_expand(t_dyn_str *dyn_str, size_t new_len)
{
	size_t	new_capacity;
	char	*new_str;

	new_capacity = get_close_power_of_2(new_len);
	new_str = (char *)safe_malloc(new_capacity * sizeof(char));
	dyn_str->capacity = new_capacity;
	ft_strcpy(new_str, dyn_str->str);
	free(dyn_str->str);
	dyn_str->str = new_str;
}
