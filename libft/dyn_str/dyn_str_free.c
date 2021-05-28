/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:39:51 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:31:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_free(t_dyn_str *dyn_str)
{
	if (dyn_str == NULL)
		return ;
	ft_memdel((void **)&dyn_str->str);
	free(dyn_str);
}
