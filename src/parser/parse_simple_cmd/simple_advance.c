/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_advance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/22 10:46:52 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	simple_advance(t_parse_simple *sim)
{
	if (sim->tokens_index == sim->tokens_len - 1)
	{
		sim->current_token.type = NA;
		return ;
	}
	++(sim->tokens_index);
	sim->current_token = sim->tokens[sim->tokens_index];
}
