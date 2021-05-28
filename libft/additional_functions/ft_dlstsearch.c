/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:57:31 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:09:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_d_list	*ft_dlstsearch(t_d_list *lst, void *obj, int (*f)())
{
	if (lst == NULL || obj == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if (f(lst, obj) == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
