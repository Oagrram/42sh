/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 07:40:33 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/08 07:52:35 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	free_hash2(t_t **root)
{
	t_t	*tail;

	if (*root == NULL)
		return ;
	tail = *root;
	free_hash2(&(tail->left));
	free_hash2(&(tail->right));
}

void	remove_hash(t_t **root)
{
	free_hash(root);
}

void	print_hash(t_t *root, char **cmd)
{
	int			len;
	static int	i = 0;
	static int	f_time = 0;

	if ((root == NULL && f_time == 0))
	{
		ft_printf(1, "hash: hash table empty\n");
		return ;
	}
	if (root->left)
		print_hash(root->left, cmd);
	if (i++ == 0)
		ft_printf(1, "hits    command\n");
	len = ft_nbrlen(root->count);
	while (len++ < 4)
		ft_printf(1, " ");
	ft_printf(1, "%d    %s\n", root->count, root->value);
	if (root->right)
		print_hash(root->right, cmd);
}
