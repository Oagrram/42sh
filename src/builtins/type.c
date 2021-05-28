/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:12 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 10:27:31 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_type(char **cmd)
{
	int		i;
	char	*full_path;

	full_path = NULL;
	i = 1;
	while (cmd[i])
	{
		if (check_builtins(cmd[i]))
		{
			ft_printf(1, "%s is a shell builtin\n", cmd[i]);
			i++;
			continue ;
		}
		full_path = get_full_path(cmd[i]);
		if (full_path && full_path[0] == '/')
		{
			ft_printf(1, "%s is %s\n", cmd[i], full_path);
			ft_strdel(&full_path);
		}
		else
			ft_printf(1, "%s not found\n", cmd[i]);
		i++;
	}
}
