/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:54:24 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/04/30 15:29:19 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_pattern(t_pattern *pattern)
{
	t_pattern	*tmp;

	while (pattern)
	{
		tmp = pattern;
		pattern = pattern->next;
		free(tmp->str);
		free(tmp);
	}
}
