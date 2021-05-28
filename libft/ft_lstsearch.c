/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:48:06 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/27 22:48:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, int (*f)(t_list *l))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if ((*f)(lst))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
