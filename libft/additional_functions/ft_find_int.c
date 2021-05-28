/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:17:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/04/30 16:48:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

_Bool	ft_find_int(int *t, int n, size_t size, size_t *index)
{
	while (size-- > 0)
	{
		if (t[size] == n)
		{
			if (index)
				*index = size;
			return (1);
		}
	}
	return (0);
}
