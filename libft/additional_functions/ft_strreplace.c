/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:04:42 by cjamal            #+#    #+#             */
/*   Updated: 2021/05/01 14:08:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strreplace(char *str, char find, char replace)
{
	if (str)
	{
		str = ft_strchr(str, find);
		if (str)
			*str++ = replace;
	}
	return (str);
}
