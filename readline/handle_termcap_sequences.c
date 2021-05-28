/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_termcap_sequences.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:16:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:27:27 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

static t_termcap_seq	g_termcap_sequences[TERMCAP_SEQ_COUNT] = {
	{"\e[1;5A", goto_previous_line},
	{"\e[1;5B", goto_next_line},
	{"\e[1;5C", goto_next_word},
	{"\e[1;5D", goto_previous_word},
	{"\e[3~", delete_next_char},
	{"\e[A", show_previous_hist_entry},
	{"\e[B", show_next_hist_entry},
	{"\e[C", goto_next_char},
	{"\e[D", goto_previous_char},
	{"\e[F", goto_end},
	{"\e[H", goto_home}
};

static t_match_state	match_termcap_sequence(char *buf, size_t buf_len,
		t_termcap_seq **termcap_seq)
{
	int		i;
	t_bool	is_partially_matched;

	i = 0;
	is_partially_matched = FALSE;
	while (i < TERMCAP_SEQ_COUNT)
	{
		if (ft_strncmp(buf, g_termcap_sequences[i].seq, buf_len) == 0)
		{
			is_partially_matched = TRUE;
			if (ft_strequ(buf, g_termcap_sequences[i].seq))
			{
				*termcap_seq = (t_termcap_seq *)g_termcap_sequences + i;
				return (MATCH);
			}
		}
		i++;
	}
	if (is_partially_matched)
		return (PARTIAL_MATCH);
	else
		return (MISMATCH);
}

int	handle_termcap_sequences(char *c)
{
	static char		buf[10] = "\e";
	t_match_state	match_state;
	t_termcap_seq	*termcap_seq;

	ft_strncat(buf, c, 1);
	match_state = match_termcap_sequence(buf, ft_strlen(buf), &termcap_seq);
	if (match_state == PARTIAL_MATCH)
		return (INCOMPLETE_SEQUENCE);
	else if (match_state == MATCH && termcap_seq->action != NULL)
		termcap_seq->action();
	ft_strcpy(buf, "\e");
	return (DONE);
}
