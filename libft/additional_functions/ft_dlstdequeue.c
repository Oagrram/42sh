/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdequeue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 00:49:40 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 13:50:42 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstdequeue(t_d_list **list, void (*del)(void **))
{
	t_d_list	*tmp;

	if (list && *list)
	{
		tmp = (*list)->next;
		if (tmp)
			tmp->tail = (*list)->tail;
		del((void **)&(*list)->content);
		ft_memdel((void **)list);
		*list = tmp;
	}
}
