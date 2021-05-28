/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:45:22 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 15:04:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*expand_string_lenght(char *var_name, char *expression)
{
	t_var	*var;

	if (*expression)
		return (NULL);
	if (assign_p(&var, get_var(var_name + 1)))
		return (ft_itoa(ft_strlen(var->value)));
	return (ft_strdup("0"));
}

char	*expand_simple(char *var_name)
{
	t_var	*var;

	if (assign_p(&var, get_var(var_name)) && !ft_strequ(var->value, ""))
		return (ft_strdup(var->value));
	return (ft_strdup(""));
}
