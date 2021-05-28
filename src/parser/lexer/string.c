/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:55:47 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 18:23:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_string	*string_new(void)
{
	t_string	*ptr;

	ptr = (t_string *)ft_malloc(sizeof(t_string));
	ptr->capacity = 1024;
	ptr->length = 0;
	ptr->data = (char *)ft_malloc(ptr->capacity);
	return (ptr);
}

void	string_free(t_string *str)
{
	free(str->data);
	str->data = NULL;
	free(str);
}

void	string_push(t_string *str, char c)
{
	char	*tmp;

	if (str->length == str->capacity)
	{
		tmp = ft_realloc(str->data, str->capacity, str->capacity * 2);
		str->capacity *= 2;
		free(str->data);
		str->data = tmp;
	}
	str->data[str->length] = c;
	++(str->length);
}

char	*string_get_data(t_string *str)
{
	char	*data;

	data = ft_strsub(str->data, 0, str->length);
	return (data);
}
