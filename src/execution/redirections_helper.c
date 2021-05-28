/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:48:32 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/04 11:51:22 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	get_word(char **word, char *r_fd, char **tmp)
{
	*word = ft_strdup(r_fd);
	*word = expand(*word, NULL);
	*tmp = ft_strtrim(*word);
	free(*word);
}
