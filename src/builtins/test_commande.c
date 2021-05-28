/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commande.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:12:40 by oagrram           #+#    #+#             */
/*   Updated: 2021/05/06 14:59:14 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	check_for_exclamation_mark(t_tokens *tokens)
{
	int	index;

	index = 1;
	while (tokens)
	{
		if (ft_strcmp("!", tokens->data) == 0 && index == 2)
			return (1);
		index++;
		tokens = tokens->next;
	}
	return (0);
}

int	count_tokens(t_tokens *tokens)
{
	int	counter;

	counter = 0;
	while (tokens)
	{
		counter++;
		tokens = tokens->next;
	}
	return (counter);
}

int	ft_is_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_binary(char *arg1, char *arg2, t_test_operation ope)
{
	int	num1;
	int	num2;

	num1 = ft_is_number(arg1);
	num2 = ft_is_number(arg2);
	if (num1 == 0 || num2 == 0)
		return (ft_error_arg(arg1, arg2, num1));
	num1 = ft_atoi(arg1);
	num2 = ft_atoi(arg2);
	if (num1 == num2 && ope == OPERATER_AL_E)
		return (0);
	if (num1 > num2 && ope == OPERATER_AL_G)
		return (0);
	if (num1 <= num2 && ope == OPERATER_AL_L_E)
		return (0);
	return (1);
}

int	test_commande(char **cmd)
{
	int			arg_num;
	int			dif;
	t_tokens	*tokens;
	t_tokens	*tmp;

	tokens = ft_convert_tab_list(cmd);
	tmp = tokens;
	arg_num = count_tokens(tokens) - 1;
	dif = check_for_exclamation_mark(tokens);
	arg_num = arg_num - dif;
	tokens = tokens->next;
	if (dif == 1)
		tokens = tokens->next;
	if (arg_num == 0)
		return (1 ^ dif);
	if (arg_num == 1)
		return (wrapper_free(!(!ft_strequ("", tokens->data)) ^ dif, &tmp));
	if (arg_num == 2)
		return (wrapper_free(check_unary_op(tokens) ^ dif, &tmp));
	if (arg_num == 3)
		return (wrapper_free(check_binary_op(tokens) ^ dif, &tmp));
	if (arg_num >= 4)
		ft_putendl_fd("42_sh: test: too many arguments", 2);
	free_test_token(&tmp);
	return (2);
}
