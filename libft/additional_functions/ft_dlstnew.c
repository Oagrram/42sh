/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:12:44 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:08:59 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_d_list	*ft_dlstnew(void const *content, size_t size)
{
	t_d_list	*lst;

	lst = NULL;
	if (content)
	{
		lst = (t_d_list *)ft_memalloc(sizeof(t_d_list));
		if (lst == NULL)
			return (NULL);
		lst->content = malloc(size);
		if (lst->content == NULL)
		{
			free(lst);
			return (NULL);
		}
		ft_memcpy(lst->content, content, size);
		lst->content_size = size;
	}
	return (lst);
}
