/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:58:06 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 13:52:13 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstiter(t_d_list *lst, void (*f)(t_d_list *elem))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst->next != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
	(*f)(lst);
}
