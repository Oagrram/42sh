/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_ul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:23:21 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:27:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ter_ul(int bool, unsigned long val1, unsigned long val2)
{
	if (bool)
		return (val1);
	else
		return (val2);
}
