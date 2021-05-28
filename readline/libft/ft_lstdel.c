/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:22:57 by mel-idri          #+#    #+#             */
/*   Updated: 2019/04/10 17:08:04 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lnk_ptr;
	t_list	*next_lnk;

	if (alst == NULL || del == NULL)
		return ;
	lnk_ptr = *alst;
	while (lnk_ptr)
	{
		next_lnk = lnk_ptr->next;
		ft_lstdelone(&lnk_ptr, del);
		lnk_ptr = next_lnk;
	}
	*alst = NULL;
}
