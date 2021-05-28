/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assignment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/20 16:47:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_var	*get_assignment_var(char *word, size_t equal_index)
{
	t_var	*var;

	var = (t_var *)ft_malloc(sizeof(t_var));
	var->key = ft_strsub(word, 0, equal_index);
	var->value = ft_strdup(word + equal_index + 1);
	return (var);
}

void	parse_assignment(t_parse_simple *sim, char *word, size_t equal_index)
{
	t_var	*assign_var;

	assign_var = get_assignment_var(word, equal_index);
	vector_push(sim->cmd->assignments, assign_var);
	free(assign_var);
}
