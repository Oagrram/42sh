/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:57:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/30 15:14:59 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*get_exit_status_str(void)
{
	static char	status[10];
	char		*st;

	st = ft_itoa(g_exit_status);
	ft_strcpy(status, st);
	status[ft_strlen(st)] = '\0';
	free(st);
	return (status);
}

char	*get_pid_str(void)
{
	static char	pid[11];
	char		*p;

	p = ft_itoa((int)getpid());
	ft_strcpy(pid, p);
	pid[ft_strlen(p)] = '\0';
	free(p);
	return (pid);
}

char	*escape_string(char *str)
{
	t_string	*escaped_str;
	size_t		i;

	escaped_str = string_new();
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			string_push(escaped_str, BACK_SLASH);
		string_push(escaped_str, str[i]);
		++i;
	}
	return (string_get_data(escaped_str));
}

char	*env_get(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	if (ft_strequ(key, "?"))
		return (get_exit_status_str());
	if (ft_strequ(key, "$"))
		return (get_pid_str());
	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
			return (vars[i].value);
		++i;
	}
	return (NULL);
}
