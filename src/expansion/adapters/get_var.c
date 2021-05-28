/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:01:14 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 16:15:09 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static t_var	*get_pid_status_var(char *key)
{
	static t_var	var;
	static char		tmp_key[2];

	ft_strcpy(tmp_key, key);
	var.key = tmp_key;
	var.value = env_get(g_shell_env, key);
	return (&var);
}

t_var	*get_var(char *key)
{
	t_var	*vars;
	size_t	i;

	if (ft_strequ(key, "?") || ft_strequ(key, "$"))
		return (get_pid_status_var(key));
	i = 0;
	vars = g_shell_env->array;
	while (i < g_shell_env->length)
	{
		if (ft_strequ(key, vars[i].key))
			return (vars + i);
		++i;
	}
	return (NULL);
}
