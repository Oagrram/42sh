/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:04 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:43:11 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_base(unsigned long long n, int base, int is_upper)
{
	static const char	*g_lower_base = "0123456789abcdef";
	static const char	*g_upper_base = "0123456789ABCDEF";

	if (n / base)
		ft_putunbr_base(n / base, base, is_upper);
	if (is_upper)
		ft_putchar(g_upper_base[n % base]);
	else
		ft_putchar(g_lower_base[n % base]);
}
