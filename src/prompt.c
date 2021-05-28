/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:19:21 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/21 10:58:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

char	*prompt_1(void)
{
	char	*user;
	char	*host;
	char	*cwd;
	char	*prompt_1;

	return (ft_strdup("$> "));
	user = ft_strdup("ylagtab");
	host = ft_strdup("e2r1p5");
	cwd = getcwd(NULL, 0);
	prompt_1 = ft_strdup("[");
	prompt_1 = ft_strjoin_free(prompt_1, user, 1, 1);
	prompt_1 = ft_strjoin_free(prompt_1, "@", 1, 0);
	prompt_1 = ft_strjoin_free(prompt_1, host, 1, 1);
	prompt_1 = ft_strjoin_free(prompt_1, "]: ", 1, 0);
	prompt_1 = ft_strjoin_free(prompt_1, cwd, 1, 1);
	prompt_1 = ft_strjoin_free(prompt_1, "\n$ ", 1, 0);
	return (prompt_1);
}
