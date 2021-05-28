/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <oagrram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:55:21 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/08 11:46:13 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_t	*get_new_node(char *key, char *value)
{
	t_t		*root;

	root = (t_t *)ft_memalloc(sizeof(t_t));
	root->key = ft_strdup(key);
	root->value = ft_strdup(value);
	root->count = 1;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

t_t	*insert_name(t_t *root, char *key, char *value)
{
	if (root == NULL)
	{
		root = get_new_node(key, value);
		return (root);
	}
	if (ft_strcmp(key, root->key) < 0)
		root->left = insert_name(root->left, key, value);
	else if (!ft_strcmp(key, root->key))
		root->count++;
	else
		root->right = insert_name(root->right, key, value);
	return (root);
}

void	ft_hash(t_t **root, char **cmd)
{
	int		i;
	char	*path;

	g_exit_status = 0;
	if (!cmd[1])
		print_hash(*root, cmd);
	else if (ft_strequ(cmd[1], "-r"))
		free_hash(root);
	else
	{
		i = 0;
		while (cmd[++i])
		{
			path = get_full_path(cmd[i]);
			if (ft_strequ(path, cmd[i]))
			{
				ft_printf(2, "42sh: hash: %s: not found\n", cmd[i]);
				g_exit_status = 1;
			}
			find_key_in_hash(*root, cmd[i], 0);
			ft_strdel(&path);
		}
	}
}

char	*find_key_in_hash(t_t *root, char *key, int hits)
{
	char	*value;

	if (root == NULL)
		return (NULL);
	if (!ft_strcmp(root->key, key))
	{
		if (hits == 1)
			root->count++;
		else
			root->count = 0;
		return (root->value);
	}
	value = find_key_in_hash(root->left, key, hits);
	if (value)
		return (value);
	value = find_key_in_hash(root->right, key, hits);
	if (value)
		return (value);
	return (NULL);
}

void	free_hash(t_t **root)
{
	t_t	*tail;

	if (*root == NULL)
		return ;
	tail = *root;
	if (tail->left)
	{
		free_hash(&(tail->left));
		free(tail->left);
		tail->left = NULL;
	}
	if (tail->right)
	{
		free_hash(&(tail->right));
		free(tail->right);
		tail->right = NULL;
	}
	ft_strdel(&(tail->key));
	ft_strdel(&(tail->value));
	free(*root);
	*root = NULL;
}
