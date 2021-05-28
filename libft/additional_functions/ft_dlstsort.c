/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:56:56 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 14:09:13 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_list_swap(t_d_list **last, t_d_list **first, t_d_list *e,
				int is_first)
{
	t_d_list	*tmp;

	if (*last != NULL)
		last[0]->next = e->next;
	tmp = e->next->next;
	e->next->next = e;
	if (is_first == 1)
		*first = e->next;
	*last = e->next;
	e->next = tmp;
	return (1);
}

static t_d_list	*ft_list_next(t_d_list **e)
{
	t_d_list	*last;

	last = e[0];
	e[0] = e[0]->next;
	return (last);
}

void	ft_dlstsort(t_d_list **begin_list, int (*cmp)())
{
	t_d_list	*first;
	t_d_list	*last;
	int			edited;
	int			is_first;

	if (begin_list == NULL || begin_list[0] == NULL)
		return ;
	edited = 1;
	first = begin_list[0];
	while (edited == 1)
	{
		last = NULL;
		is_first = 1;
		edited = 0;
		begin_list[0] = first;
		while (begin_list[0]->next != NULL)
		{
			if ((*cmp)(begin_list[0], begin_list[0]->next) > 0)
				edited = ft_list_swap(&last, &first, begin_list[0], is_first);
			else
				last = ft_list_next(&begin_list[0]);
			is_first = 0;
		}
	}
	begin_list[0] = first;
}
