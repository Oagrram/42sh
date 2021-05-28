/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:41:52 by zoulhafi          #+#    #+#             */
/*   Updated: 2021/05/01 13:52:18 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstdelone(t_d_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	(*del)(alst[0][0].content, alst[0][0].content_size);
	free(*alst);
	*alst = NULL;
}
