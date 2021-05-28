/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapters.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:43:20 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 15:29:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADAPTERS_H
# define ADAPTERS_H

void	edit_add_var(char *key, char *value, int a, int b);
t_var	*get_var(char *key);
int		is_number(char *str);

#endif