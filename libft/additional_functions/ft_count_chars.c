/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:33:17 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/04/30 15:31:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_count_chars(const char *str, const char *chars)
{
	long	count;

	count = 0;
	while (*str)
		count += ft_isinstr(*str, chars);
	return (count);
}
