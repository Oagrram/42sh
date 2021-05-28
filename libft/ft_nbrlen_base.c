/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:05:39 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:41:40 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen_base(unsigned long long nbr, int base)
{
	int	len;

	len = 1;
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
