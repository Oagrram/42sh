/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:26:11 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 11:10:52 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

void	env_set(t_vector *env, char *key, char *value, t_bool is_exported);
void	env_unset(t_vector *env, char *key);
void	env_set_exported(t_vector *env, char *key, t_bool is_exported);
t_bool	is_valid_identifier(char *name);
char	*get_key_from_string(char *str);
char	*get_value_from_string(char *str);
t_var	*string_to_var(char *str);

#endif
