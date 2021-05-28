# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 16:45:44 by mel-idri          #+#    #+#              #
#    Updated: 2021/05/04 13:50:46 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra  -Werror
ifeq ($(DEBUG), true)
	CFLAGS = -g -Wall -Wextra
endif
CC = gcc

LIBFT_INC = libft.h
LIBFT_SRC = ft_autoalloc.c ft_nbrlen.c ft_nbrlen_base.c ft_atoi.c \
	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c \
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_lstsearch.c ft_max.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putnchar.c ft_putstr.c ft_putstr_fd.c \
	ft_putunbr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strichr.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	ft_toupper.c ft_putunbr_base.c ft_write_buff.c \
	ft_queue_new.c ft_enqueue.c ft_dequeue.c \
	ft_strglue.c ft_strjoin_free.c ft_strdup_free.c ft_lst_pushback.c \
	ft_lst_pushback_str.c safe_malloc.c ft_free_list.c ft_memdup.c \
	ft_strndup.c remove_chars.c skip_chars.c skip_until_chars.c \
	ft_free_2d_chr_array.c ft_free_ptr.c ft_iscntrl.c
LIBFT_OBJ = $(addprefix $(OBJS_DIR)/, $(LIBFT_SRC:.c=.o))

VECTOR_INC = vector/vector.h vector/internal/vector_internal.h
VECTOR_SRC = vector_free.c vector_grow.c vector_init.c \
	vector_insert.c vector_pop.c vector_pop_index.c vector_push.c \
	vector_remove.c vector_shrink.c vector_insert_all.c vector_grow_above.c
VECTOR_OBJ = $(addprefix $(OBJS_DIR)/, $(VECTOR_SRC:.c=.o))

DYNSTR_INC = dyn_str/dyn_str.h dyn_str/internal/dyn_str_internal.h
DYNSTR_SRC = dyn_str_delete_chr.c dyn_str_util.c dyn_str_shrink.c dyn_str_expand.c \
	dyn_str_create.c dyn_str_insert_chr.c dyn_str_free.c dyn_str_append.c \
	dyn_str_insert.c dyn_str_append_chr.c dyn_str_fill.c dyn_str_delete.c \
	dyn_str_dup.c dyn_str_clone.c
DYNSTR_OBJ = $(addprefix $(OBJS_DIR)/, $(DYNSTR_SRC:.c=.o))

OBJS_DIR = objs

ALL_OBJS = $(LIBFT_OBJ) $(VECTOR_OBJ) $(DYNSTR_OBJ)

all: $(NAME)

$(NAME): $(ALL_OBJS)
	ar rc $(NAME) $(ALL_OBJS)


objs/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

objs/%.o : */%.c
	$(CC) $(CFLAGS) -c $< -o $@

objs/%.o : */*/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ALL_OBJS) : $(LIBFT_INC) | $(OBJS_DIR)

$(VECTOR_OBJ): $(VECTOR_INC)

$(DYNSTR_OBJ): $(DYNSTR_INC)

$(OBJS_DIR):
	mkdir objs


clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all fclean re clean
