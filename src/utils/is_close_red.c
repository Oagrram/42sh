/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_close_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:10:06 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/03 16:13:42 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	is_close_red(t_redirection *red)
{
	return (red->type == GREATANDDASH
		|| red->type == LESSANDDASH
		|| (ft_strequ(red->righ_fd, "-")
			&& (red->type == GREATAND
				|| red->type == LESSAND)));
}
