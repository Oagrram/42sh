/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:41:28 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 13:35:03 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int a, int b)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (a == 1)
		free((void *)s1);
	if (b == 1)
		free((void *)s2);
	return (str);
}
