/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:06:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:45:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_queue_new(void)
{
	t_queue	*queue;

	queue = ft_autoalloc(sizeof(t_queue *));
	ft_bzero(queue, sizeof(t_queue));
	return (queue);
}
