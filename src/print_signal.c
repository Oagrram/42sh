/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:40:14 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/06 16:46:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	print_signal(int ret_status)
{
	int	signal;

	signal = WTERMSIG(ret_status);
	if (signal == 2)
		return ;
	ft_printf(1, "received signal : %d\n", signal);
}
