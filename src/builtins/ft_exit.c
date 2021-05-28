/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:30:12 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/03 11:54:59 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_exit(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
	{
		ft_printf(2, "Too many arguments\n");
		g_exit_status = 1;
	}
	else if (cmd[0] || cmd[1])
	{
		if (cmd[1])
		{
			if (ft_str_isnumeric(cmd[1]))
				exit(ft_atoi(cmd[1]));
			g_exit_status = 1;
			ft_printf(2, "42sh: exit: numeric argument required\n");
			g_exit_status = 1;
			return ;
		}
		else
			exit(0);
	}
}
