/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:47:00 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 13:50:21 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstdel(t_d_list **alst, void (*del)(void *, size_t))
{
	t_d_list	*cpy;
	t_d_list	*next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	cpy = *alst;
	while (cpy->next != NULL)
	{
		next = cpy->next;
		(*del)(cpy->content, cpy->content_size);
		free(cpy);
		cpy = next;
	}
	(*del)(cpy->content, cpy->content_size);
	free(cpy);
	*alst = NULL;
}

void	ft_dlstdel2(t_d_list **alst, void (*del)(void *))
{
	t_d_list	*to_free;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			to_free = *alst;
			*alst = to_free->next;
			(*del)(to_free->content);
			free(to_free);
		}
	}
}
