/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:12:04 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:52:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_INTERNAL_H
# define READLINE_INTERNAL_H
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# undef lines
# include "libft/libft.h"
# include "readline_typedefs.h"
# define TERMCAP_SEQ_COUNT 11
# define DONE 0
# define INCOMPLETE_SEQUENCE 1
# define STDOUT_FD 1
# define STDIN_FD 0
# define STDERR_FD 2
# define SIGINT_HANDLER 0
# define SIGWINCH_HANDLER 1
# ifndef VDSUSP
#  define VDSUSP -1
# endif

extern t_readline_state	g_rl_state;
extern t_history_state	g_history;
extern t_term_attrs		g_orig_attrs;
extern t_bool			g_is_interrupted;

int				handle_termcap_sequences(char *c);
void			exit_error(char *msg);
void			write_char(char c);
void			init_readline_state(size_t prompt_len);
void			move_cursor_to(int line, int cursor_line_pos);
void			reprint_line(void);
void			update_lines(void);
void			goto_next_char(void);
void			goto_previous_char(void);
void			handle_control_chars(char c);
void			delete_prev_char(void);
void			delete_next_char(void);
void			merge_lines(int dest_line, int src_line);
void			goto_home(void);
void			goto_end(void);
void			goto_next_word(void);
void			goto_previous_word(void);
void			goto_next_line(void);
void			goto_previous_line(void);
void			yank_clipboard(void);
void			wrap_cursor(void);
void			kill_cursor_to_end(void);
void			show_previous_hist_entry(void);
void			show_next_hist_entry(void);
void			init_history_state(void);
void			print_current_hist_entry(void);
void			print_newline(void);
void			free_dyn_str(void *ptr);
t_dynstr_vector	*clone_dynstr_vector(t_dynstr_vector *orig_dynstr_vector);
int				dynstr_vector_equ(t_dynstr_vector *dynstr_vec1,
					t_dynstr_vector *dynstr_vec2);
void			mark_hist_entry_as_dirty(void);
char			*submit_command(void);
void			test_multiline(void);
int				reprint_char(void);
int				check_used_capabilities(void);
void			reset_readline_state(void);
void			free_history_allocs(void);
t_dynstr_vector	*str_to_dynstr_vec(char *str);
char			*dynstr_vec_to_str(t_dynstr_vector *dynstr_vec);
void			add_hist_entry(char *entry_str);
void			append_to_last_hist_entry(char *partial_entry);
char			*get_last_hist_entry(void);
void			update_win_dimensions(void);
void			set_signal_handlers(sig_t *signals);
void			restore_signal_handlers(sig_t *signals);

#endif
