/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_and_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/06 15:21:28 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <dirent.h>

void	get_word(char **word, char *r_fd, char **tmp);

int	manage_pipes(int i)
{
	static int		fd[2];

	if (i == -1)
	{
		if (pipe(fd) == -1)
			exit(0);
		dup2(fd[1], 1);
		close(fd[1]);
		return (fd[0]);
	}
	else if (i == 2)
	{
		return (close(fd[0]));
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

static int	free_all(t_vector *splitted_words, char *a, char *b, t_bool e)
{
	vector_free(splitted_words);
	if (e)
	{
		free(a);
		ft_printf(2, "42sh: %s ambiguous redirect\n", b);
	}
	return (EXIT_FAILURE);
}

static int	expand_red(t_vector *red_vec)
{
	t_vector		*splitted_words;
	t_redirection	*reds;
	char			*word;
	char			*tmp;
	size_t			i;

	i = -1;
	reds = red_vec->array;
	while (++i < red_vec->length)
	{
		if (reds[i].type == GREATANDDASH || reds[i].type == LESSANDDASH)
		{
			++i;
			continue ;
		}
		get_word(&word, reds[i].righ_fd, &tmp);
		splitted_words = split(tmp, del_arg);
		if (splitted_words->length != 1)
			return (free_all(splitted_words, tmp, reds[i].righ_fd, TRUE));
		word = reds[i].righ_fd;
		reds[i].righ_fd = tmp;
		free(word);
		free_all(splitted_words, tmp, NULL, FALSE);
	}
	return (EXIT_SUCCESS);
}

int	ft_error(char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (access(str, F_OK) == 0)
	{
		if (dir)
			ft_printf(2, "42sh: %s: Is a directory\n", str);
		else
			ft_printf(2, "42sh: %s: Permission denied\n", str);
	}
	else
		ft_printf(2, "42sh: %s: No such file or directory\n", str);
	if (dir)
		closedir(dir);
	return (-1);
}

int	do_pipes_and_red(int i, int len, t_vector *red)
{
	static int	fd = -1;

	if (fd != -1)
		fd = manage_pipes(fd);
	if (i + 1 < len)
		fd = manage_pipes(-1);
	if (red)
	{
		if (expand_red(red) == EXIT_FAILURE || do_redirections(red) == -1)
			return (1);
	}
	return (fd);
}
