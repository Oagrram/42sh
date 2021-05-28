/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:00:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 16:08:03 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_bool	is_quote(char c)
{
	return (c == SINGLE_QUOTE || c == DOUBLE_QUOTE || c == BACK_SLASH);
}

t_bool	quote_type(char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE || c == BACK_SLASH)
		return (c);
	return (0);
}
