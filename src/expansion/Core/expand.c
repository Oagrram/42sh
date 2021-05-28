/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:27:30 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/06 14:20:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static char	*expand_tilde(char *str)
{
	t_var	*var;
	char	*tmp;

	if (str && *str == '~')
	{
		if (str[1] == '/' || str[1] == '\0')
		{
			var = get_var("HOME");
			if (var != NULL)
				tmp = ft_strjoin(var->value, str + 1);
			else
				tmp = ft_strdup(str + 1);
			free(str);
			str = tmp;
		}
		else if (getpwnam(str + 1))
		{
			tmp = ft_strjoin("/Users/", str + 1);
			free(str);
			str = tmp;
		}
	}
	return (str);
}

static char	*join_expan_result(t_parser_expansion result, char **str)
{
	char	*tmp;
	char	*ret;

	tmp = *str;
	if (assign_p(str, ft_strnjoin(
				(char *[]){tmp, result.str, result.index}, 3)))
	{
		ret = *str + ft_strlen(result.str) + ft_strlen(tmp);
		free(tmp);
		free(result.str);
		return (ret);
	}
	free(tmp);
	free(result.str);
	return (NULL);
}

char	*expand(char *str, t_parser_expansion (*expand_fun)(char *))
{
	char				*tmp;
	int					qoute;
	t_parser_expansion	result;

	str = expand_tilde(str);
	tmp = str;
	qoute = 0;
	while (tmp && *tmp)
	{
		if (*tmp == '\\')
			tmp++;
		else if (!qoute && *tmp == '$' && tmp[1] && !ft_strchr(" \t\n", tmp[1]))
		{
			expand_fun = ter_p(tmp[1] == '(', expand_sub_art, expand_parametre);
			result = expand_fun(&tmp[1]);
			*tmp = 0;
			if (!result.str || !assign_p(&tmp, join_expan_result(result, &str)))
				return (NULL);
			continue ;
		}
		else if (*tmp == '\'')
			qoute ^= 1;
		tmp++;
	}
	return (str);
}
