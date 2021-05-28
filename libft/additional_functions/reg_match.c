/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:26:35 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/04 11:49:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_pattern	*split_pattern(char *patrn)
{
	t_pattern	*head;
	t_pattern	**ptr;
	char		*tmp;

	head = NULL;
	ptr = &head;
	while (*patrn && assign_p(ptr, ft_memalloc(sizeof(t_pattern))))
	{
		if (assign_p(&tmp, get_matched_bracket(patrn, "[]", "[", 1)) && patrn++)
			(*ptr)->type = PT_CHAR_SEQ;
		else if (*patrn == '^' && head->next == NULL && assign_p(&tmp, patrn))
			(*ptr)->type = PT_START;
		else if (*patrn == '*' && assign_p(&tmp, patrn))
			(*ptr)->type = PT_STAR;
		else if (*patrn == '?' && assign_p(&tmp, patrn))
			(*ptr)->type = PT_QMARK;
		else if (*patrn == '$' && patrn[1] == 0 && assign_p(&tmp, patrn))
			(*ptr)->type = PT_END;
		else if (assign_p(&tmp, patrn))
			(*ptr)->type = PT_CHAR;
		(*ptr)->str = ft_strsub(patrn, 0, tmp - patrn + ((*ptr)->type != 4));
		patrn = tmp + 1;
		ptr = &(*ptr)->next;
	}
	return (head);
}

static char	*pattern_sanitize(char *pattern)
{
	char	*sanitized_string;
	int		i;

	sanitized_string = pattern;
	i = 0;
	while (*pattern)
	{
		if (*pattern == '\\')
			sanitized_string[i++] = *++pattern;
		else if (!(*pattern == '*' && pattern[1] == '*'))
			sanitized_string[i++] = *pattern;
		if (*pattern)
			pattern++;
	}
	sanitized_string[i++] = 0;
	return (sanitized_string);
}

t_d_list	*get_star_match(char *str, t_pattern *pattern)
{
	t_d_list	*ret;

	ret = NULL;
	if (pattern->next && pattern->next->type == PT_END)
	{
		while (*str)
			str++;
		if (assign_p(&ret, ft_memalloc(sizeof(t_d_list))))
			ret->content = str;
	}
	else
	{
		while (1)
		{
			ft_dlstenqueue(&ret, is_matched(str, pattern->next));
			if (!*str)
				break ;
			str++;
		}
	}
	return (ret);
}

t_d_list	*is_matched(char *str, t_pattern *p)
{
	t_d_list	*ret;
	int			matched;

	matched = 1;
	p = ter_p(p && p->type == PT_START, p->next, p);
	while (p && *str && matched)
	{
		if (p->type == PT_STAR)
			return (get_star_match(str, p));
		else if (p->type == PT_QMARK)
			str++;
		else if (p->type == PT_CHAR)
			(*(p->str) == *str && (str++ || 1)) || matched--;
		else if (p->type == PT_CHAR_SEQ)
			(ft_isinstr(*str, p->str) && (str++ || 1)) || matched--;
		else
			return (NULL);
		ter_p(matched, (p = p->next), 0);
	}
	if ((p && p->type != 5) || !assign_p(&ret, ft_memalloc(sizeof(t_d_list))))
		return (NULL);
	ret->content = str;
	return (ret);
}

t_d_list	*reg_match(char *str, char *str_pattern)
{
	t_matched_strings	ptr;
	t_d_list			*starts;
	t_d_list			*ends;
	t_pattern			*pattern;

	starts = NULL;
	if (assign_p(&pattern, split_pattern(pattern_sanitize(str_pattern))))
	{
		while (*str)
		{
			if (assign_p(&ends, is_matched(str, pattern)))
			{
				ptr.start = str;
				ptr.ends = ends;
				ft_dlstenqueue(&starts, ft_dlstnew(&ptr,
						sizeof(t_matched_strings)));
			}
			str++;
			if (pattern->type == PT_START)
				break ;
		}
	}
	free_pattern(pattern);
	return (starts);
}
