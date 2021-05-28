/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:30:49 by mel-idri          #+#    #+#             */
/*   Updated: 2019/10/07 13:11:30 by ylagtab          ###   ########.fr       */
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
