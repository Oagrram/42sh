/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:26:38 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/16 22:03:06 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYN_STR_INTERNAL_H
# define DYN_STR_INTERNAL_H
# include "../../libft.h"
# include "../dyn_str.h"

void	dyn_str_expand(t_dyn_str *dyn_str, size_t new_len);
void	dyn_str_shrink(t_dyn_str *dyn_str);
size_t	get_close_power_of_2(size_t	n);
#endif
