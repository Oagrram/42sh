/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:18:45 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 13:23:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_H
# define ARITHMETIC_H

# include "expansion.h"
# define HEX_BASE "0123456789abcdef"
# define OCTAL_BASE "01234567"

long long	do_op(long long *op1, int oparator, long op2, int ret);
int			do_logical_op(t_d_list **token, long long *result, int operator);
int			get_precedence(int operator);
int			operator_have_precedence(t_d_list **token, int operator1);
void		ar_edit_var(char *key, long long val, int prefix);

long long	convert_operand(t_d_list **token, long long *result);
int			convert_operator(t_d_list **token, int *result, int skip_token);
int			eval_expr(t_d_list **tokens, long long *result);
t_d_list	*parse_number(char **expression);
t_d_list	*parse_variable(char **expr);
t_d_list	*parse_ar_expression(char **expression, t_d_list *token);

#endif
