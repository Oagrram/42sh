/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_array_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:58:41 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:51:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strings_array_length(char **arr)
{
	size_t	len;

	if (arr == NULL)
		return (0);
	len = 0;
	while (arr[len])
		++len;
	return (len);
}
