/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_used_capabilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:35:13 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

int	check_used_capabilities(void)
{
	int				i;
	char *const		used_capabilities[9] =
	{"LI", "RI", "DO", "UP", "le", "vi", "ve", "cd", NULL};

	i = 0;
	if (tgetent(NULL, getenv("TERM")) != 1)
		exit_error("tgetent: terminal type not recognized");
	while (used_capabilities[i])
	{
		if (tgetstr(used_capabilities[i], NULL) == NULL)
			return (-1);
		i++;
	}
	return (0);
}
