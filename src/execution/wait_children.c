/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:54:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/06 16:50:00 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	wait_children(pid_t ret_pid)
{
	pid_t	pid;
	int		wait_status;
	int		ret_status;

	pid = waitpid(-1, &wait_status, 0);
	ret_status = 0;
	while (pid++ == -1)
	{
		pid = waitpid(-1, &wait_status, 0);
		if (pid == -1)
			break ;
		if (pid == ret_pid)
			ret_status = wait_status;
	}
	if (WIFSIGNALED(ret_status))
		print_signal(ret_status);
	return (ret_status);
}
