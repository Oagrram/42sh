/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:08:39 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:07:40 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

char	*submit_command(void)
{
	goto_end();
	ft_putchar('\n');
	return (dynstr_vec_to_str(g_rl_state.lines));
}
