/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expansion_parse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 04:17:51 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 13:22:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

int	get_sign(char **expression)
{
	int		sign;
	char	*tmp;

	sign = 1;
	while (1)
	{
		*expression = ft_skip_chars(*expression, " ", NULL);
		if (!ft_isinstr(**expression, "+-"))
			break ;
		else if (expression[0][1] == **expression)
		{
			tmp = ft_skip_chars(*expression + 2, " ", NULL);
			if (*tmp == '_' || ft_isalpha(*tmp))
				break ;
		}
		sign *= (44 - *(*expression)++);
	}
	*expression = ft_skip_chars(*expression, " ", NULL);
	return (sign);
}

t_d_list	*get_operand(char **expression, t_d_list *token)
{
	t_d_list	*ptr;

	ptr = NULL;
	if (get_sign(expression) == -1)
		ft_dlstenqueue(&token, ft_dlstnew("-", 2));
	if (**expression == '(')
	{
		*expression = ft_skip_chars(*expression + 1, " ", NULL);
		ptr = parse_ar_expression(expression, ft_dlstnew("(", 2));
	}
	else if (ft_isdigit(**expression))
		ft_dlstenqueue(&ptr, parse_number(expression));
	else
		ft_dlstenqueue(&ptr, parse_variable(expression));
	*expression = ft_skip_chars(*expression, " ", NULL);
	ft_dlstenqueue(&token, ptr);
	if (!ptr)
		ft_dlstdel2(&token, free);
	return (token);
}

t_d_list	*get_operator(char **expr, t_d_list *token)
{
	static char	*operators[14] = {"||", "&&", "!=", "==", ">=", "<=", ">",
								"<", "-", "+", "%", "/", "*", 0};
	int			i;
	t_d_list	*ptr;

	ptr = NULL;
	i = 0;
	*expr = ft_skip_chars(*expr, " ", NULL);
	while (operators[i])
	{
		if (ft_strnequ(*expr, operators[i], ft_strlen(operators[i])))
		{
			*expr = ft_skip_chars(*expr + ft_strlen(operators[i]), " ", NULL);
			ptr = (ft_dlstnew(operators[i], ft_strlen(operators[i]) + 1));
			break ;
		}
		i++;
	}
	ft_dlstenqueue(&token, ptr);
	if (!ptr)
		ft_dlstdel2(&token, free);
	return (token);
}

int	get_parentese(char **expression, t_d_list **token)
{
	if (**expression == ')')
	{
		ft_dlstenqueue(token, ft_dlstnew((char []){')', 0}, 2));
		(*expression)++;
		return (1);
	}
	ft_dlstdel2(token, free);
	return (0);
}

t_d_list	*parse_ar_expression(char **expression, t_d_list *token)
{
	int			i;
	const int	need_bracket_close = token && ft_strequ(token->content, "(");

	i = 0;
	*expression = ft_skip_chars(*expression, " ", NULL);
	while (**expression && **expression != ')')
	{
		if (!(i % 2) && !assign_p(&token, get_operand(expression, token)))
			return (NULL);
		else if ((i % 2) && !assign_p(&token, get_operator(expression, token)))
			return (NULL);
		i = (i + 1) % 2;
	}
	if (need_bracket_close)
		get_parentese(expression, &token);
	if (i == 0)
		ft_dlstdel2(&token, free);
	return (token);
}
