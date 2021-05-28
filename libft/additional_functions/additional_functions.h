/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:22:12 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 10:10:49 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_FUNCTIONS_H
# define ADDITIONAL_FUNCTIONS_H

typedef struct s_pattern
{
	int					type;
	char				*str;
	struct s_pattern	*next;
}					t_pattern;

enum
{
	PT_START,
	PT_QMARK,
	PT_STAR,
	PT_CHAR,
	PT_CHAR_SEQ,
	PT_END
};

typedef struct s_d_list
{
	void			*content;
	size_t			content_size;
	struct s_d_list	*previous;
	struct s_d_list	*next;
	struct s_d_list	*tail;
}	t_d_list;

typedef struct s_matched_strings
{
	char		*start;
	t_d_list	*ends;
}	t_matched_strings;

void		ft_dlstadd(t_d_list **alst, t_d_list *new);
void		ft_dlstadd_end(t_d_list **alst, t_d_list *new);
void		ft_dlstdelone(t_d_list **alst, void (*del)(void*, size_t));
void		ft_dlstdel(t_d_list **alst, void (*del)(void *, size_t));
void		ft_dlstdel2(t_d_list **alst, void (*del)(void *));
void		ft_dlstcontent_iter(t_d_list *lst, void (*f)(void *content));
t_d_list	*ft_dlstnew(void const *content, size_t size);
t_d_list	*ft_dlstmap(t_d_list *lst, t_d_list *(*f)(t_d_list *elem));
size_t		ft_dlstlen(t_list *lst);
void		ft_dlstiter(t_d_list *lst, void (*f)(t_d_list *elem));
t_d_list	*ft_dlstenqueue(t_d_list **list, t_d_list *new);
void		ft_dlstdequeue(t_d_list **list, void (*del)(void **));
void		ft_dlstrev(t_d_list **begin_list);
void		ft_dlstsort(t_d_list **begin_list, int (*cmp)());
t_d_list	*ft_dlstsearch(t_d_list *lst, void *obj, int (*f)());
void		free_content_list(t_list **list, size_t size);
void		free_pattern(t_pattern *pattern);
long long	ft_atoi_base(const char *s, const char *s_base, int base);
long		ft_count_chars(const char *str, const char *chars);
char		*ft_skip_chars(const char *str, const char *compare, int (*f)(int));
char		*ft_rskip_chars(const char *str, const char *cmp,
				int (*f)(int), int i);
void		ft_die(const char *message, int error_nb);
_Bool		ft_find_int(int *t, int n, size_t size, size_t *index);
int			ft_isinstr(char c, const char *s);
int			ft_isnalnum(int c);
int			ft_strindexof(const char *s, char c);
char		*ft_strreplace(char *str, char find, char replace);
long		ft_max(long a, long b);
long		ft_min(long a, long b);
char		*get_matched_bracket(char *str, const char *bracket,
				char *to_skip, int escaping);
t_d_list	*get_star_match(char *str, t_pattern *pattern);
t_d_list	*is_matched(char *str, t_pattern *pattern);
t_d_list	*reg_match(char *str, char *str_pattern);
char		*ft_skip_unitl_char(const char *str, const char *compare,
				int (*f)(int));
char		*ft_rskip_unitl_char(const char *str, const char *compare,
				int (*f)(int), int i);
char		*ft_strnjoin(char **strings, int n);

#endif