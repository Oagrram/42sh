/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_typedefs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:12:08 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:52:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_TYPEDEFS_H
# define READLINE_TYPEDEFS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_term_attrs
{
	struct termios	attrs;
	t_bool			is_initialized;
}					t_term_attrs;
typedef struct s_termcap_seq
{
	char			*seq;
	void			(*action)(void);
}					t_termcap_seq;
typedef struct s_dynstr_vector
{
	size_t			capacity;
	size_t			length;
	size_t			element_size;
	void			(*free_element)(void *element);
	t_dyn_str		*array;
}					t_dynstr_vector;
typedef struct s_hist_entry
{
	t_dynstr_vector	*entry;
	t_dynstr_vector	*temp;
	t_bool			is_dirty;
}					t_hist_entry;
typedef struct s_hist_vector
{
	size_t			capacity;
	size_t			length;
	size_t			element_size;
	void			(*free_element)(void *element);
	t_hist_entry	*array;
}					t_hist_vector;
typedef struct s_history_state
{
	int				current_entry;
	t_hist_vector	*entries;
	t_dynstr_vector	*stage;
}					t_history_state;
typedef struct s_readline_state
{
	size_t			prompt_len;
	int				win_cols;
	int				win_rows;
	size_t			current_line;
	size_t			cursor_line_pos;
	t_dyn_str		*clipboard;
	t_dynstr_vector	*lines;
}					t_readline_state;
typedef enum e_match_state
{
	MATCH = 1,
	PARTIAL_MATCH,
	MISMATCH
}					t_match_state;
typedef enum e_readline_ret
{
	ERROR = -1,
	EXIT = 0,
	LINE,
	INTERRUPTED
}					t_readline_ret;
#endif
