# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/05/08 07:54:11 by oagrram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	variables																   #
# **************************************************************************** #

# name
NAME = 42sh
LIBFT = libft/libft.a
PARSER = src/parser/parser.a
JOBS = src/execution/job_control/job_control.a
READLINE = readline/readline.a
EXPANSION = src/expansion/expansion.a
LIBFT_OPT = "LIBFT_EXIT_ON_ALLOC_FAIL=1"

# compilation variables
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
CC = gcc
LIBS_ENV=42sh_headers=$(mkfile_dir)/includes/forty_two_sh.h 42sh_include_dirs=-I$(mkfile_dir)includes/

# 42sh																		   #
INCLUDES =	-Iincludes

42sh_INC =	includes/forty_two_sh.h includes/typedefs.h includes/constants.h \
			src/errors/errors.h

42sh = 	delete_functions.o main.o signal.o errors/errors.o free_funcs.o \
	execution/exec_tools.o \
	execution/execute_commands.o \
	execution/execute_logic_seq.o \
	execution/execute_pipe_seq.o \
	execution/execute_simple_cmd.o \
	execution/pipes_and_red.o \
	execution/redirections_helper.o \
	execution/get_exit_code.o \
	execution/redirections.o \
	execution/remove_quotes.o \
	execution/wait_children.o \
	prompt.o \
	builtins/export.o \
	builtins/job_builtins.o \
	builtins/ft_echo.o \
	builtins/ft_exit.o \
	builtins/test_commande.o \
	builtins/test_commande2.o \
	builtins/test_commande3.o \
	builtins/test_con_tab_list.o \
	builtins/hash.o \
	builtins/hash2.o \
	builtins/type.o \
	builtins/cd.o \
	builtins/cd_helper.o \
	builtins/cd_helper2.o \
	execution/builtins.o \
	read_cmd_multiline/read_cmd_multiline.o \
	utils/is_quote.o utils/is_close_red.o utils/is_space.o \
	builtins/set.o builtins/unset.o \
	env/env.o env/env_dup.o env/env_get.o env/env_operations.o env/utils.o \
	print_signal.o


42sh_OBJS = $(addprefix $(OBJS_DIR)/, ${42sh})

# objects directory
OBJS_DIR = objs

#
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(42sh_OBJS) $(LIBFT) $(PARSER) $(READLINE) $(JOBS) $(EXPANSION)
	$(CC) -o $(NAME) $(42sh_OBJS) $(PARSER) $(READLINE) $(JOBS) $(EXPANSION) $(LIBFT) -ltermcap

$(LIBFT): force
	@env $(LIBFT_OPT) make -C libft/

$(PARSER): force
	@env $(LIBS_ENV) make -C src/parser/

$(EXPANSION): force
	@env $(LIBS_ENV) make -C src/expansion/

$(JOBS): force
	make -C src/execution/job_control

 $(READLINE) : force
	@make -C readline

force:

$(OBJS_DIR)/%.o : src/%.c $(42sh_INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	make clean -C src/execution/job_control
	make clean -C readline

fclean: clean
	make fclean -C libft/
	make fclean -C src/parser/
	make fclean -C src/expansion/
	make fclean -C src/execution/job_control
	make fclean -C readline
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re libft force
