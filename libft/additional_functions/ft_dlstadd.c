/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:55:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:03:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstadd(t_d_list **alst, t_d_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	if (*alst)
		(*alst)->previous = new;
	*alst = new;
}
