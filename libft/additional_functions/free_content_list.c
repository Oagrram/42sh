/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_content_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:48:05 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/04/30 15:28:12 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_content_list(t_list **list, size_t size)
{
	t_list	*tmp;

	(void)size;
	while (*list)
	{
		tmp = *list;
		list = &(*list)->next;
		free(tmp->content);
		free(tmp);
	}
}
