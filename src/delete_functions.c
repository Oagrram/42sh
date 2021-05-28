/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:08:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/03 16:31:00 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	del_token(void *element)
{
	t_token	*token;

	token = (t_token *)element;
	if (token->type == WORD || token->type == IO_NUMBER)
		free(token->data);
}

void	del_redirection(void *element)
{
	t_redirection	*redirect;

	redirect = (t_redirection *)element;
	free(redirect->righ_fd);
}

void	del_var(void *element)
{
	t_var	*var;

	var = (t_var *)element;
	free(var->key);
	free(var->value);
}

void	del_arg(void *el)
{
	free(*((char **)el));
}
