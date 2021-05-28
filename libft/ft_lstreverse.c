/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:46:52 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:38:14 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*next;
	t_list	*prev;

	if (alst == NULL || *alst == NULL || (*alst)->next == NULL)
		return ;
	prev = NULL;
	while (*alst)
	{
		next = (*alst)->next;
		(*alst)->next = prev;
		prev = *alst;
		*alst = next;
	}
	*alst = prev;
}
