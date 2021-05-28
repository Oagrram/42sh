/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluation_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 05:17:28 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/04 11:41:50 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

static int	convert_variable(t_d_list **token, long long *result)
{
	int			prefix;
	int			postfix;
	char		*tmp[2];
	t_var		*var;

	prefix = 0;
	postfix = 0;
	var = NULL;
	*tmp = (*token)->content;
	if (ft_isinstr(**tmp, "-+"))
	{
		prefix = 44 - **tmp;
		*tmp += 2;
	}
	tmp[1] = ft_skip_chars(*tmp, "_", ft_isalnum);
	if (ft_isinstr(tmp[1][0], "+-"))
	{
		postfix = (44 - tmp[1][0]) * !prefix;
		tmp[1][0] = 0;
	}
	if (assign_p(&var, get_var(*tmp)) && !is_number(var->value))
		return (1);
	*result = ter_i(var != NULL, ft_atoi(var->value), 0) + prefix;
	ar_edit_var(*tmp, *result + postfix, postfix || prefix);
	return (0);
}

long long	convert_operand(t_d_list **token, long long *result)
{
	int	sign;
	int	error;

	if (!*token)
		return (1);
	assign_i(&sign, 1) && assign_i(&error, 0);
	if (ft_strequ((*token)->content, "-") && assign_i(&sign, -1))
		*token = (*token)->next;
	if (ft_strequ((*token)->content, "(")
		&& (assign_p(token, (*token)->next) || 1))
		error = eval_expr(token, result);
	else if (ft_isdigit(*((char *)(*token)->content)))
	{
		if (ft_strnequ((*token)->content, "0x", 2))
			*result = ft_atoi_base((*token)->content + 2, HEX_BASE, 16);
		else if (ft_strnequ((*token)->content, "0", 1))
			*result = ft_atoi_base((*token)->content, OCTAL_BASE, 8);
		else
			*result = ft_atoi((*token)->content);
	}
	else
		error = convert_variable(token, result);
	*token != NULL && assign_p(token, (*token)->next);
	*result *= sign;
	return (error);
}

int	convert_operator(t_d_list **token, int *result, int skip_token)
{
	static char	*opertrs[14] = {"||", "&&", "!=", "==", ">", "<", ">=", "<=",
								"-", "+", "%", "/", "*", 0};
	int			i;

	i = 0;
	if (!*token)
		return (1);
	while (opertrs[i])
	{
		if (ft_strnequ((*token)->content, opertrs[i], ft_strlen(opertrs[i])))
			break ;
		i++;
	}
	if (ft_between(i, 0, 12))
	{
		if (skip_token)
			*token = (*token)->next;
		*result = i + 1;
		return (0);
	}
	return (1);
}

int	eval_expr(t_d_list **tokens, long long *result)
{
	int			has_error;
	int			operator;
	long long	operand2;

	has_error = convert_operand(tokens, result);
	while (*tokens && !has_error && !ft_strequ((*tokens)->content, ")"))
	{
		has_error = convert_operator(tokens, &operator, 1);
		if (!has_error && (operator == 1 || operator == 2))
		{
			has_error = do_logical_op(tokens, result, operator);
			continue ;
		}
		if (!has_error && operator_have_precedence(tokens, operator))
			has_error = convert_operand(tokens, &operand2);
		else if (!has_error)
			has_error = eval_expr(tokens, &operand2);
		if (!has_error)
			has_error = do_op(result, operator, operand2, 0);
	}
	return (has_error);
}

char	*expand_ar_expr(char *expr)
{
	t_d_list	*tokens;
	t_d_list	*tokens_tmp;
	long long	result;
	int			status;

	result = 0;
	tokens = parse_ar_expression(&expr, NULL);
	tokens_tmp = tokens;
	if (assign_i(&status, eval_expr(&tokens, &result)))
	{
		if (status == 2)
			ft_printf(1, "divised by zero\n");
		else
		{
			if (!tokens)
				ft_printf(1, "token error: (null)\n");
			else
				ft_printf(1, "token error: %s\n", tokens->content);
		}
		ft_dlstdel2(&tokens_tmp, free);
		return (NULL);
	}
	ft_dlstdel2(&tokens_tmp, free);
	return (ft_itoa(result));
}
