/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autoalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:41:59 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:52:52 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alloc_list	*g_allocs;

void	ft_autofree_all(void)
{
	t_alloc_list	*tmp;

	while (g_allocs)
	{
		tmp = g_allocs;
		g_allocs = g_allocs->next;
		free(tmp->address);
		free(tmp);
	}
	g_allocs = NULL;
}

void	*ft_autoalloc(size_t size)
{
	void			*ptr;
	t_alloc_list	*node;
	t_alloc_list	*tmp;

	ptr = ft_memalloc(size);
	node = (t_alloc_list *)ft_memalloc(sizeof(t_alloc_list));
	if (ptr == NULL || node == NULL)
	{
		free(ptr);
		ft_autofree_all();
		return (NULL);
	}
	node->address = ptr;
	if (g_allocs == NULL)
		g_allocs = node;
	else
	{
		tmp = g_allocs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (ptr);
}
