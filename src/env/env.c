/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:01:18 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 14:52:28 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*g_shell_env;

t_vector	*env_init(char **envp)
{
	t_vector	*env;
	t_var		var;
	int			equal_index;

	env = vector_init(sizeof(t_var), del_var);
	while (*envp)
	{
		equal_index = ft_strichr(*envp, '=');
		if (equal_index == -1)
			continue ;
		var.key = ft_strsub(*envp, 0, equal_index);
		if (ft_strequ(var.key, "SHELL"))
			var.value = ft_strdup("42sh");
		else
			var.value = ft_strdup(*envp + equal_index + 1);
		var.is_exported = TRUE;
		vector_push(env, &var);
		++envp;
	}
	return (env);
}

char	**env_to_envp(t_vector *env)
{
	t_var	*vars;
	char	**envp;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (vars[i++].is_exported == TRUE)
			++len;
	}
	i = 0;
	j = 0;
	envp = (char **)ft_malloc((len + 1) * sizeof(char *));
	while (i < env->length)
	{
		if (vars[i].is_exported == TRUE)
			envp[j++] = ft_strglue(vars[i].key, '=', vars[i].value);
		++i;
	}
	envp[j] = NULL;
	return (envp);
}

void	env_print(t_vector *env, t_bool print_exported_only)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (print_exported_only == FALSE || vars[i].is_exported == TRUE)
		{
			ft_printf(1, "declare -x %s", vars[i].key);
			if (vars[i].value != NULL)
				ft_printf(1, "=\"%s\"", vars[i].value);
			ft_printf(1, "\n");
		}
		++i;
	}
}
