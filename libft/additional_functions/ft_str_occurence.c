/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_occurence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:44:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 14:07:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_occurence(char *str, char c)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		str = ft_strreplace(str, c, c);
		i += ter_i((size_t)str, 1, 0);
	}
	return (i);
}
