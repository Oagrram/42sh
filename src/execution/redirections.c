/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:39:53 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/03 16:14:58 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	open_files_for_red(t_redirection *red)
{
	int	fd;

	fd = -1;
	if (red->type == GREAT || red->type == GREATAND || red->type == ANDGREAT)
		fd = open(red->righ_fd, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (red->type == DGREAT)
		fd = open(red->righ_fd, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (red->type == LESS)
	{
		fd = open(red->righ_fd, O_RDWR);
		if (fd == -1)
			return (ft_error(red->righ_fd));
	}
	if (red->type == GREATAND || red->type == LESSAND)
		dup2(fd, 2);
	if (red->type == LESS || red->type == LESSAND)
		dup2(fd, 0);
	else if (red->left_fd != -1)
		dup2(fd, red->left_fd);
	else if (!(red->type == DLESS))
		dup2(fd, 1);
	if (fd != -1)
		close(fd);
	return (1);
}

int	str_is_number(char *str, t_token_type type)
{
	int	i;

	i = -1;
	if (type != GREATANDDASH && type != LESSANDDASH)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
		}
	}
	return (1);
}

int	check_is_word(t_redirection *red)
{
	if ((red->type == GREATAND
			&& str_is_number(red->righ_fd, red->type))
		|| (red->type == LESSAND
			&& str_is_number(red->righ_fd, red->type))
		|| is_close_red(red))
		return (1);
	else
		return (0);
}

int	if_not_word(t_redirection *red)
{
	int	fd;

	fd = -1;
	if (red->left_fd == -1)
		fd = 1;
	else
		fd = red->left_fd;
	if (red->left_fd == -1
		&& (red->type == GREATAND || red->type == GREATANDDASH))
		red->left_fd = 1;
	if (is_close_red(red))
		close(red->left_fd);
	else if (red->righ_fd)
	{
		if (dup2(ft_atoi(red->righ_fd), fd) == -1)
		{
			ft_printf(2, "42sh: %d: bad file descriptor\n",
				ft_atoi(red->righ_fd));
			return (-1);
		}
	}
	return (EXIT_SUCCESS);
}

int	do_redirections(t_vector *red)
{
	int				i;
	t_redirection	*redi;

	i = -1;
	redi = (t_redirection *)red->array;
	while (++i < (int)red->length)
	{
		if (redi[i].type == DLESS)
		{
			if (redi[i].left_fd == -1)
				redi[i].left_fd = 0;
			dup2(ft_atoi(redi[i].righ_fd), redi[i].left_fd);
			close(ft_atoi(redi[i].righ_fd));
		}
		if (check_is_word(&redi[i]))
		{
			if (if_not_word(&redi[i]) == -1)
				return (-1);
		}
		else
			if (open_files_for_red(&redi[i]) == -1)
				return (-1);
	}
	return (1);
}
