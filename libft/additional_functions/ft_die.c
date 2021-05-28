/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 02:04:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 14:15:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_die(const char *message, int error_nb)
{
	if (error_nb != 0 && message)
		ft_printf(2, "%s\n", message);
	else if (message)
		ft_printf(1, "%s\n", message);
	exit(error_nb);
}
