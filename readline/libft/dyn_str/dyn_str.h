/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:41:31 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 12:20:55 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYN_STR_H
# define DYN_STR_H

typedef struct s_dyn_str
{
	char		*str;
	size_t		len;
	size_t		capacity;
}				t_dyn_str;
typedef enum e_delete_mode
{
	BY_SIZE,
	TO_END,
	TO_START
}				t_delete_mode;
t_dyn_str		*dyn_str_create(size_t initial_capacity);
void			dyn_str_free(t_dyn_str *dyn_str);
void			dyn_str_insert(t_dyn_str *dyn_str, size_t i, char *str);
void			dyn_str_insert_chr(t_dyn_str *dyn_str, size_t i, char c);
void			dyn_str_delete_chr(t_dyn_str *dyn_str, size_t i);
void			dyn_str_append(t_dyn_str *dyn_str, char	*str);
void			dyn_str_append_chr(t_dyn_str *dyn_str, char c);
void			dyn_str_delete(t_dyn_str *dyn_str, size_t i,
					t_delete_mode delete_mode, size_t size);
t_dyn_str		*dyn_str_fill(t_dyn_str *dyn_str, size_t initial_capacity);
t_dyn_str		*dyn_str_dup(t_dyn_str *dyn_str, char *str);
t_dyn_str		*dyn_str_clone(t_dyn_str *container, t_dyn_str *old_dyn_str);

#endif
