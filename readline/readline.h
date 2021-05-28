/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:31:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:12:40 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef enum e_readline_ret
{
	ERROR = -1,
	EXIT = 0,
	LINE,
	INTERRUPTED
}					t_readline_ret;
void				add_hist_entry(char *entry_str);
void				append_to_last_hist_entry(char *partial_entry);
char				*get_last_hist_entry(void);
t_readline_ret		readline_21sh(char **line, char *prompt);

#endif
