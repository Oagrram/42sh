/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:28:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/03 18:10:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_bool	is_valid_identifier(char *name)
{
	size_t	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (FALSE);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

char	*get_key_from_string(char *str)
{
	int		equal_index;

	equal_index = ft_strichr(str, '=');
	if (equal_index == -1)
		return (ft_strdup(str));
	return (ft_strsub(str, 0, equal_index));
}

char	*get_value_from_string(char *str)
{
	int		equal_index;

	equal_index = ft_strichr(str, '=');
	if (equal_index == -1)
		return (NULL);
	return (ft_strdup(str + equal_index + 1));
}

t_var	*string_to_var(char *str)
{
	t_var	*var;
	int		equal_index;

	var = ft_malloc(sizeof(t_var));
	equal_index = ft_strichr(str, '=');
	if (equal_index == -1)
	{
		var->key = ft_strdup(str);
		var->value = NULL;
		var->is_exported = FALSE;
	}
	else
	{
		var->key = ft_strsub(str, 0, equal_index);
		var->value = ft_strdup(str + equal_index + 1);
		var->is_exported = FALSE;
	}
	return (var);
}
