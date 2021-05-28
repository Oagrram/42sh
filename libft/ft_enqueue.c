/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:19:41 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 16:58:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *queue, void *content, size_t content_size)
{
	t_list	*node;

	if (queue == NULL)
		return ;
	node = ft_lstnew(content, content_size);
	if (queue->length == 0)
	{
		queue->head = node;
		queue->tail = node;
		queue->length = 1;
		return ;
	}
	queue->tail->next = node;
	queue->tail = node;
	queue->length++;
}
