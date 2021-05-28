/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:28:52 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:48:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "vector/vector.h"
# include "dyn_str/dyn_str.h"
# define BUFF_SIZE 4096

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
int				ft_isupper(int c);
int				ft_islower(int c);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
int				ft_putchar(int c);
int				ft_putnchar(char c, int n);
int				ft_putstr(char const *str);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putunbr(unsigned long long n);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstsearch(t_list *lst, int (*f)(t_list *l));
size_t			ft_strichr(const char *s, int c);
void			ft_strrev(char *s);
int				ft_nbrlen(__uint128_t unbr);
int				ft_nbrlen_base(unsigned long long n, int base);
int				ft_max(int nbr1, int nbr2);
void			ft_putunbr_base(unsigned long long n, int base, int is_upper);
typedef struct s_alloc_list
{
	void				*address;
	struct s_alloc_list	*next;
}				t_alloc_list;
void			ft_autofree_all(void);
void			*ft_memdup(void *src, size_t n);
void			*ft_autoalloc(size_t size);
int				ft_write_buff(char *str, size_t size);
void			ft_flush_buff(void);
int				ft_printf(char *format, ...);

typedef struct s_queue
{
	t_list		*head;
	t_list		*tail;
	size_t		length;
}				t_queue;

t_queue			*ft_queue_new(void);
void			ft_enqueue(t_queue *queue, void *content, size_t content_size);
t_list			*ft_dequeue(t_queue *queue);

typedef enum e_split_mode
{
	ALLOW_EMPTY_WORD,
	REJECT_EMPTY_WORD
}				t_split_mode;
char			**ft_strsplit2(char const *s, char c, t_split_mode split_mode);
char			*ft_strglue(char const *s1, char glue, char const *s2);
char			*ft_strdup_free(const char **s);
char			*ft_strjoin_free(char const *s1, char const *s2, int a, int b);
int				ft_lst_pushback(t_list **alst, t_list *new);
int				ft_lst_pushback_str(t_list	**alst, char *str);
void			ft_free_list(t_list *head);
char			*ft_strndup(const char *s, size_t n);
void			*safe_malloc(size_t size);
char			*skip_until_chars(char *str, char *stop_chars);
char			*skip_chars(char *str, char *skipped_chars);
void			ft_free_2d_chr_array(char **arr);
void			ft_free_ptr(void *ptr);
int				ft_iscntrl(char c);

typedef unsigned long	t_ul;

t_ul			assign_ul(unsigned long *ret, unsigned long value);
int				assign_i(int *ret, int value);
void			*assign_p(void *ret, void *value);
char			assign_c(char *ret, char value);
long			ter_l(int bool, long val1, long val2);
int				ter_i(int bool, int val1, int val2);
uint64_t		ter_ul(int bool, unsigned long val1, unsigned long val2);
void			*ter_p(int bool, void *val1, void *val2);
uint32_t		ter_ui(int bool, uint32_t val1, uint32_t val2);
#endif
