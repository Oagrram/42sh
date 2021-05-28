/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:01:56 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/27 22:34:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstjoin(t_list *lst)
{
	t_list	*tmp;
	char	*res;

	res = ft_strdup("");
	while (lst)
	{
		res = ft_strjoin_free(res, (char *)lst->content, 1, 0);
		lst = lst->next;
	}
	return (res);
}
