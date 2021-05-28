/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:57:28 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:03:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstadd_end(t_d_list **alst, t_d_list *new)
{
	t_d_list	*cpy;

	if (alst == NULL || new == NULL)
		return ;
	cpy = *alst;
	if (cpy == NULL)
	{
		*alst = new;
		return ;
	}
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = new;
	new->previous = cpy;
}
