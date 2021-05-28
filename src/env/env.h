/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:26:22 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/01 09:55:08 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

extern t_vector	*g_shell_env;

char		*env_get(t_vector *env, char *key);
t_vector	*env_init(char **envp);
t_vector	*env_dup(t_vector *env);
char		**env_to_envp(t_vector *env);
void		env_print(t_vector *env, t_bool print_exported_only);
void		env_set(t_vector *env, char *key, char *value, t_bool is_exported);
void		env_set_value(t_vector *env, char *key, char *value);
void		env_set_exported(t_vector *env, char *key, t_bool is_exported);
void		env_unset(t_vector *env, char *key);
t_bool		is_valid_identifier(char *name);
char		*get_key_from_string(char *str);
char		*get_value_from_string(char *str);
t_var		*string_to_var(char *str);

#endif
