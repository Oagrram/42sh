/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:37:35 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/01 09:55:17 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*env_dup(t_vector *env)
{
	t_vector	*new_env;
	t_var		*vars;
	t_var		v;
	size_t		i;

	new_env = vector_init_capacity(env->element_size, env->capacity,
			env->free_element);
	vars = env->array;
	i = 0;
	while (i < env->length)
	{
		v.key = ft_strdup(vars[i].key);
		v.value = ft_strdup(vars[i].value);
		v.is_exported = vars[i].is_exported;
		vector_push(new_env, &v);
		++i;
	}
	return (new_env);
}
