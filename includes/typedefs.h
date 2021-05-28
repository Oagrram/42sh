/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:18:55 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/06 14:46:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef enum e_token_type {
	START,
	WORD,
	ASSIGNMENT,
	IO_NUMBER,
	GREAT,
	ANDGREAT,
	DGREAT,
	ANDDGREAT,
	LESS,
	DLESS,
	GREATAND,
	LESSAND,
	GREATANDDASH,
	LESSANDDASH,
	PIPE,
	OROR,
	ANDAND,
	SEMI,
	AMPERSAND,
	NEWLINE,
	NA
}			t_token_type;

typedef struct s_var
{
	char	*key;
	char	*value;
	t_bool	is_exported;
}				t_var;

typedef enum e_cmd_type
{
	SIMPLE_CMD,
	PIPE_SEQ,
	LOGIC_SEQ
}				t_cmd_type;

typedef struct s_token
{
	t_token_type	type;
	void			*data;
}				t_token;

/*
** void *command = switch(type):
** 	type = SIMPLE_CMD ==> t_simple_command
**	type = PIPE_SEQ ==> t_pipe_sequence
**	type = LOGIC_SEQ ==> t_logic_sequence
*/
typedef struct s_command
{
	t_cmd_type	type;
	t_bool		is_background_job;
	void		*command;
}				t_command;

/*
** - right_fd:
**  if type == GREATAND || type == LESSAND
** 	 switch(str_is_number(right_fd)):
**    TRUE => right_fd is an io_number
**    FALSE => right_fd is a filename
**  else if type == DLESS
**   right_fd is an io_number
**  else
**   right_fd is a filename
*/
typedef struct s_redirection
{
	t_token_type	type;
	int				left_fd;
	char			*righ_fd;
}				t_redirection;

/*
** t_vector *args [char *]
** t_vector *redirections [t_redirection]
*/
typedef struct s_simple_command
{
	t_vector	*args;
	t_vector	*redirections;
	t_vector	*assignments;
	char		*job_name;
}				t_simple_command;

/*
** t_vector *commands [t_simple_command]
*/
typedef struct s_pipe_sequence
{
	t_vector	*commands;
	char		*job_name;
}				t_pipe_sequence;

/*
** t_vector *commands [t_command]
** t_vector	*logic_ops [t_token_type]
*/
typedef struct s_logic_sequence
{
	t_vector	*commands;
	t_vector	*logic_ops;
	char		*job_name;
}				t_logic_sequence;

typedef enum e_run_state
{
	UNDEFINED,
	RUNNING,
	STOPPED,
	COMPLETED
}				t_run_state;

typedef struct s_job
{
	u_int32_t	id;
	t_bool		is_background;
	pid_t		pgid;
	t_run_state	state;
	struct		s_count
	{
		int		running;
		int		stopped;
		int		completed;
	}			count;
	t_vector	*processes;
	t_bool		to_notify;
	pid_t		ret_pid;
	int			wait_status;
	char		*job_name;
}				t_job;

typedef struct s_process
{
	t_run_state		state;
	int				wait_status;
	pid_t			pid;
}				t_process;

typedef enum e_job_print_mode
{
	NORMAL,
	LONG,
	PGID
}				t_job_print_mode;

typedef struct s_special_jobs
{
	t_job	*current;
	t_job	*previous;
}				t_special_jobs;

typedef struct s_tree
{
	char			*key;
	char			*value;
	int				count;
	struct s_tree	*right;
	struct s_tree	*left;
}				t_t;

// dynamic string
typedef struct s_string
{
	char	*data;
	size_t	capacity;
	size_t	length;
}				t_string;

// remove quotes
typedef struct s_remove_quotes
{
	t_string	*str;
	int			i;
	char		quote;
	t_bool		backslash;
}				t_remove_quotes;

//test  amine
//user/ group /other
// b: clock_file
// c: character-special
// d: file is directory
// e: file exist
// f: file exist and regular
// g: setgid stikibit
// l: is symblonk link
// p: file like pipe
// r: clock_file
// SS: soket file
// S: exist and not empty
// U: setuid
// W: writing permission
// X: file is executable
// Z: empty line
typedef enum e_test_flags
{
	FlAG_B=1,
	FlAG_C,
	FlAG_D,
	FlAG_E,
	FlAG_F,
	FlAG_G,
	FlAG_L,
	FlAG_P,
	FlAG_R,
	FlAG_SS,
	FlAG_S,
	FlAG_U,
	FlAG_W,
	FlAG_X,
	FlAG_Z
}	t_test_flags;

// =
// != :Returns true if string1 and string2 are not equal
//-eq :True if argument arg1 equals arg2.
//-ne :True if argument arg1 is not equal to arg2.
//-ge :True if numeric value arg1 is greater than or equal to arg2.
//-lt :True if numeric value arg1 is less than arg2.
//-le :True if numeric value arg1 is less than or equal to arg2.

typedef enum e_test_operation
{
	OPERATER_E=1,
	OPERATER_RE,
	OPERATER_AL_E,
	OPERATER_NO_AL_R,
	OPERATER_AL_G,
	OPERATER_AL_L,
	OPERATER_AL_L_E,
}	t_test_operation;

typedef struct s_tokens
{
	char			*data;
	struct s_tokens	*next;
}	t_tokens;

#endif
