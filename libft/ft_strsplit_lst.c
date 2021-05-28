/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:24:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:54:34 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strsplit_lst(char const *s, char c)
{
	t_list	*head;
	t_list	*tmp;
	char	**tab;
	int		i;

	tab = ft_strsplit(s, c);
	if (tab[0] == 0)
		return (NULL);
	head = ft_lstnew(tab[0], ft_strlen(tab[0]));
	tmp = head;
	i = 1;
	while (tab[i])
	{
		tmp->next = ft_lstnew(tab[i], ft_strlen(tab[i]));
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (head);
}
