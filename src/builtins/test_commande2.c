/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commande2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <oagrram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:17:35 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/06 13:10:34 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_test_flags	check_flags_test2(t_tokens *tokens)
{
	t_test_flags	flags;

	if (ft_strcmp(tokens->data, "-r") == 0)
		flags = FlAG_R;
	if (ft_strcmp(tokens->data, "-S") == 0)
		flags = FlAG_SS;
	if (ft_strcmp(tokens->data, "-s") == 0)
		flags = FlAG_S;
	if (ft_strcmp(tokens->data, "-u") == 0)
		flags = FlAG_U;
	if (ft_strcmp(tokens->data, "-w") == 0)
		flags = FlAG_W;
	if (ft_strcmp(tokens->data, "-x") == 0)
		flags = FlAG_X;
	if (ft_strcmp(tokens->data, "-z") == 0)
		flags = FlAG_Z;
	return (flags);
}

t_test_flags	check_flags_test(t_tokens *tokens)
{
	t_test_flags	flags;

	flags = 0;
	if (ft_strcmp(tokens->data, "-b") == 0)
		flags = FlAG_B;
	if (ft_strcmp(tokens->data, "-c") == 0)
		flags = FlAG_C;
	if (ft_strcmp(tokens->data, "-d") == 0)
		flags = FlAG_D;
	if (ft_strcmp(tokens->data, "-e") == 0)
		flags = FlAG_E;
	if (ft_strcmp(tokens->data, "-f") == 0)
		flags = FlAG_F;
	if (ft_strcmp(tokens->data, "-g") == 0)
		flags = FlAG_G;
	if (ft_strcmp(tokens->data, "-L") == 0)
		flags = FlAG_L;
	if (ft_strcmp(tokens->data, "-p") == 0)
		flags = FlAG_P;
	flags = check_flags_test2(tokens);
	return (flags);
}

t_test_operation	ft_check_operateur(t_tokens *tokens)
{
	t_test_operation	operater;

	if (ft_strcmp(tokens->data, "=") == 0)
		operater = OPERATER_E;
	if (ft_strcmp(tokens->data, "!=") == 0)
		operater = OPERATER_RE;
	if (ft_strcmp(tokens->data, "-eq") == 0)
		operater = OPERATER_AL_E;
	if (ft_strcmp(tokens->data, "-ne") == 0)
		operater = OPERATER_NO_AL_R;
	if (ft_strcmp(tokens->data, "-ge") == 0)
		operater = OPERATER_AL_G;
	if (ft_strcmp(tokens->data, "-lt") == 0)
		operater = OPERATER_AL_L;
	if (ft_strcmp(tokens->data, "-le") == 0)
		operater = OPERATER_AL_L_E;
	return (operater);
}

void	ft_error_unary(char *error)
{
	ft_putstr_fd("42_sh: test:", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(": unary operator expected", 2);
}

int	ft_error_arg(char *arg1, char *arg2, int num1)
{
	ft_putstr_fd("42_sh: test:", 2);
	if (num1 == 0)
		ft_putstr_fd(arg1, 2);
	else
		ft_putstr_fd(arg2, 2);
	ft_putendl_fd(": integer expression expected", 2);
	return (2);
}
