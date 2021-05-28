/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:54:11 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 13:45:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

t_readline_state	g_rl_state;
t_history_state		g_history;
t_term_attrs		g_orig_attrs;

void	init_term(void)
{
	struct termios	new_attrs;

	new_attrs = g_orig_attrs.attrs;
	new_attrs.c_lflag &= ~(ECHO | ICANON);
	new_attrs.c_cc[VTIME] = 0;
	new_attrs.c_cc[VMIN] = 1;
	if (VDSUSP >= 0)
		new_attrs.c_cc[VDSUSP] = _POSIX_VDISABLE;
	if (tcsetattr(0, TCSANOW, &new_attrs) == -1)
		exit_error("tcsetattr: cannot set terminal attribute");
}

void	restore_term(void)
{
	if (tcsetattr(0, TCSANOW, &g_orig_attrs.attrs) == -1)
		exit_error("tcsetattr: cannot set terminal attribute");
}

char	*readline_read_loop(void)
{
	t_bool	is_in_seq;
	char	c;
	int		ret;

	is_in_seq = FALSE;
	while (assign_i(&ret, read(0, &c, 1)) > 0)
	{
		if (!is_in_seq && c == '\e')
			is_in_seq = TRUE;
		else if (is_in_seq)
			is_in_seq = handle_termcap_sequences(&c);
		else if (c == '\n')
			return (submit_command());
		else if ((c == '\0' && g_is_interrupted) || (c == 4
				&& g_rl_state.lines->length == 1
				&& g_rl_state.lines->array[0].len == 0))
			return (NULL);
		else if (ft_isprint(c))
			write_char(c);
		else if (ft_iscntrl(c))
			handle_control_chars(c);
	}
	if (ret == -1)
		exit_error("read: cannot read from stdin");
	return (NULL);
}

char	*readline(char *prompt)
{
	char			*line;
	sig_t			sig_handlers[2];

	line = NULL;
	if (tcgetattr(0, &g_orig_attrs.attrs) == -1)
		exit_error("tcgetattr: cannot get terminal attribute");
	g_orig_attrs.is_initialized = TRUE;
	check_used_capabilities();
	set_signal_handlers(sig_handlers);
	init_term();
	init_readline_state(ft_strlen(prompt));
	init_history_state();
	ft_putstr(prompt);
	line = readline_read_loop();
	free_history_allocs();
	restore_signal_handlers(sig_handlers);
	restore_term();
	return (line);
}

t_readline_ret	readline_21sh(char **line, char *prompt)
{
	if (line == NULL || prompt == NULL)
		return (ERROR);
	*line = readline(prompt);
	if (g_is_interrupted && *line == NULL)
	{
		g_is_interrupted = 0;
		return (INTERRUPTED);
	}
	else if (*line == NULL)
		return (EXIT);
	else
		return (LINE);
}
