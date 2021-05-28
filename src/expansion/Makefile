# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 10:14:12 by ylagtab           #+#    #+#              #
#    Updated: 2021/05/02 16:14:11 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = expansion.a

# compilation variables
INCLUDE_DIRS = -I. $(42sh_include_dirs)
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) -g
CC = gcc

# EXPANSION																		   #
HEADERS = expansion.h Arithmetic/arithmetic.h adapters/adapters.h $(42sh_headers)

EXPANSION = Arithmetic/ar_parse_helper.o \
	Arithmetic/arithmetic_expansion_parse.o \
	Arithmetic/evaluation_core.o \
	Arithmetic/evaluation_helper.o \
	Core/expand_args.o \
	Core/expand.o \
	Core/expand_parametre.o \
	Core/expand_sub_art.o \
	Parametre/expand_operator.o \
	Parametre/expand_remove.o \
	Parametre/expand_simple.o \
	Substitution/substitution.o \
	adapters/edit_add_var.o \
	adapters/get_var.o \
	adapters/is_number.o


OBJS = $(addprefix $(OBJS_DIR)/, ${EXPANSION})

# objects directory
OBJS_DIR = objs

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(OBJS_DIR)/%.o :%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re force
