/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_multiline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:02:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/06 17:27:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	remove_ending_backslash(char *cmd_line)
{
	size_t	cmd_len;

	cmd_len = ft_strlen(cmd_line);
	if (cmd_line[cmd_len - 1] == BACK_SLASH)
	{
		cmd_line[cmd_len - 1] = '\0';
		return ;
	}
}

static t_read_multiline	*read_multiline_init(void)
{
	t_read_multiline	*ptr;

	ptr = (t_read_multiline *)ft_malloc(sizeof(t_read_multiline));
	ptr->line = NULL;
	ptr->cmd_line = ft_strdup("");
	ptr->lex_ret = NULL;
	ptr->prompt = prompt_1();
	ptr->read_ret = LINE;
	return (ptr);
}

static void	free_lex_ret(t_lexer_ret **lex_ret)
{
	vector_free((*lex_ret)->tokens);
	free((*lex_ret));
	*lex_ret = NULL;
}

static char	*get_line(t_read_multiline *m)
{
	char			*cmd_line;

	if (m->read_ret == ERROR)
		exit(-1);
	if (m->read_ret == EXIT && m->prompt == NULL)
	{
		ft_putstr("exit\n");
		exit(0);
	}
	if (m->lex_ret)
		free_lex_ret(&(m->lex_ret));
	if (m->read_ret == INTERRUPTED)
	{
		free(m->cmd_line);
		cmd_line = NULL;
	}
	else
		cmd_line = m->cmd_line;
	free(m);
	return (cmd_line);
}

char	*read_cmd_multiline(void)
{
	t_read_multiline	*m;
	t_bool				is_first_read;

	m = read_multiline_init();
	is_first_read = TRUE;
	while (1)
	{
		m->read_ret = readline_21sh(&(m->line), m->prompt);
		if (is_first_read)
			ft_strdel(&(m->prompt));
		if (m->read_ret != LINE)
			break ;
		m->cmd_line = ft_strjoin_free(m->cmd_line, m->line, 1, 1);
		m->lex_ret = lexer(m->cmd_line);
		if (m->lex_ret->is_matched == TRUE)
			break ;
		if (m->lex_ret->unmatched_char == BACK_SLASH)
			remove_ending_backslash(m->cmd_line);
		else
			m->cmd_line = ft_strjoin_free(m->cmd_line, "\n", 1, 0);
		free_lex_ret(&(m->lex_ret));
		is_first_read = FALSE;
		m->prompt = "> ";
	}
	return (get_line(m));
}
