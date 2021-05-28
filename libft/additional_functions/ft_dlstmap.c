/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:11:00 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:08:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_d_list	*ft_dlstmap(t_d_list *lst, t_d_list *(*f)(t_d_list *elem))
{
	t_d_list	*new_list;
	t_d_list	*begin;
	t_d_list	*tmp;

	new_list = (t_d_list *)malloc(sizeof(t_d_list));
	begin = new_list;
	if (lst == NULL || new_list == NULL || f == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		tmp = (*f)(lst);
		new_list->content = ft_strdup(tmp->content);
		new_list->content_size = tmp->content_size;
		new_list->next = (t_d_list *)malloc(sizeof(t_d_list));
		new_list = new_list->next;
		lst = lst->next;
	}
	tmp = (*f)(lst);
	new_list->content = ft_strdup(tmp->content);
	new_list->content_size = tmp->content_size;
	new_list->next = NULL;
	return (begin);
}
