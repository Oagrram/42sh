/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:28:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/30 08:00:20 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	env_push(t_vector *env, char *key, char *value, t_bool is_exported)
{
	t_var	new_var;

	new_var.key = ft_strdup(key);
	new_var.value = ft_strdup(value);
	new_var.is_exported = is_exported;
	vector_push(env, &new_var);
}

void	env_set(t_vector *env, char *key, char *value, t_bool is_exported)
{
	t_var	*vars;
	char	*tmp;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vars[i].is_exported = is_exported;
			tmp = vars[i].value;
			vars[i].value = ft_strdup(value);
			free(tmp);
			return ;
		}
		++i;
	}
	env_push(env, key, value, is_exported);
}

void	env_set_value(t_vector *env, char *key, char *value)
{
	t_var	*vars;
	char	*tmp;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			tmp = vars[i].value;
			vars[i].value = ft_strdup(value);
			free(tmp);
			return ;
		}
		++i;
	}
	env_push(env, key, value, FALSE);
}

void	env_set_exported(t_vector *env, char *key, t_bool is_exported)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vars[i].is_exported = is_exported;
			return ;
		}
		++i;
	}
	env_push(env, key, NULL, is_exported);
}

void	env_unset(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vector_remove(env, i);
			return ;
		}
		++i;
	}
}
