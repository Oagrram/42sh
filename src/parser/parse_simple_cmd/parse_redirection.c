/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 14:08:25 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static int	syntax_error(t_parse_simple *sim)
{
	if (sim->current_token.type == NA)
		g_errno = ESYNTAX;
	else
		unexpected_token(sim->current_token.type);
	return (EXIT_FAILURE);
}

static void	set_left_fd(t_parse_simple *sim, t_redirection *redirect)
{
	if (sim->current_token.type == IO_NUMBER)
		redirect->left_fd = ft_atoi(sim->current_token.data);
	else
		redirect->left_fd = -1;
}

static int	set_right_fd(t_parse_simple *sim, t_redirection *redirect)
{
	int				here_doc_fd;

	if (redirect->type == DLESS)
	{
		here_doc_fd = parse_here_doc(sim->current_token.data);
		if (here_doc_fd == -1)
			return (EXIT_FAILURE);
		redirect->righ_fd = ft_itoa(here_doc_fd);
	}
	else
		redirect->righ_fd = ft_strdup(sim->current_token.data);
	return (EXIT_SUCCESS);
}

int	parse_redirection(t_parse_simple *sim)
{
	t_redirection	redirect;

	set_left_fd(sim, &redirect);
	if (redirect.left_fd != -1)
		simple_advance(sim);
	redirect.type = sim->current_token.type;
	if (redirect.type != GREATANDDASH && redirect.type != LESSANDDASH)
	{
		simple_advance(sim);
		if (sim->current_token.type != WORD || sim->current_token.type == NA)
			return (syntax_error(sim));
		if (set_right_fd(sim, &redirect) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	vector_push(sim->cmd->redirections, &redirect);
	return (EXIT_SUCCESS);
}
