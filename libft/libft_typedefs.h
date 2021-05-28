/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:56:12 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/01 14:25:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPEDEFS_H
# define LIBFT_TYPEDEFS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_alloc_list
{
	void				*address;
	struct s_alloc_list	*next;
}	t_alloc_list;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct s_queue
{
	t_list		*head;
	t_list		*tail;
	size_t		length;
}				t_queue;

typedef struct s_list_fd
{
	int					fd;
	char				*rest;
	struct s_list_fd	*next;
}				t_list_fd;

typedef struct s_element {
	void	*content;
	size_t	content_size;
}				t_element;

typedef struct s_bigint
{
	char	*digits;
	size_t	length;
}				t_bigint;
typedef enum e_split_mode
{
	ALLOW_EMPTY_WORD,
	REJECT_EMPTY_WORD
}				t_split_mode;

#endif
