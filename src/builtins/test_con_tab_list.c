/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_con_tab_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <oagrram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:53:21 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/06 10:54:26 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	free_test_token(t_tokens **tokens)
{
	t_tokens	*tmp;
	t_tokens	*start;

	start = *tokens;
	while (start)
	{
		tmp = start->next;
		ft_strdel(&start->data);
		free(start);
		start = tmp;
	}
}

int	wrapper_free(int ret, t_tokens **tokens)
{
	free_test_token(tokens);
	return (ret);
}

t_tokens	*new_node(char *data)
{
	t_tokens	*node;

	node = (t_tokens *)malloc(sizeof(t_tokens));
	node->data = ft_strdup(data);
	node->next = NULL;
	return (node);
}

t_tokens	*ft_convert_tab_list(char **cmd)
{
	t_tokens	*head;
	t_tokens	*tmp;
	int			i;

	i = 0;
	head = NULL;
	tmp = NULL;
	while (cmd[i])
	{
		if (head == NULL)
		{
			head = new_node(cmd[i]);
			tmp = head;
		}
		else
		{
			tmp->next = new_node(cmd[i]);
			tmp = tmp->next;
		}
		i++;
	}
	return (head);
}
