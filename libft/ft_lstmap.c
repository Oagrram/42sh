/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:37:09 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:37:00 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem),
	void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = (*f)(lst);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (*f)(lst);
		if (tmp->next == NULL)
		{
			ft_lstdel(&head, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
