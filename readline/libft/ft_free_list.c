/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 00:48:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:51:29 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp->content);
		free(tmp);
		tmp = head;
	}
}
