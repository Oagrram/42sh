/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_append_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:03:21 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/22 10:39:21 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_append_chr(t_dyn_str *dyn_str, char c)
{
	if (dyn_str->len + 2 >= dyn_str->capacity)
		dyn_str_expand(dyn_str, dyn_str->len + 2);
	dyn_str->str[dyn_str->len] = c;
	dyn_str->str[dyn_str->len + 1] = '\0';
	dyn_str->len++;
}
