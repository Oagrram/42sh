# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 10:14:12 by ylagtab           #+#    #+#              #
#    Updated: 2021/05/01 10:42:07 by hmzah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = parser.a

# compilation variables
INCLUDE_DIRS = -I. -Ilexer/ -Iparse_simple_cmd/ -Iparse_pipe/ \
	-Iparse_and_or/ $(42sh_include_dirs)
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) -g
CC = gcc

# 42sh																		   #
HEADERS = parser.h internals.h lexer/lexer.h lexer/internals.h \
	parse_simple_cmd/parse_simple_cmd.h parse_simple_cmd/internals.h \
	parse_pipe/parse_pipe.h parse_pipe/internals.h \
	parse_and_or/parse_and_or.h parse_and_or/internals.h $(42sh_headers)

PARSER = lexer/lexer.o lexer/lexer_advance.o lexer/lexer_handle_io_number.o \
	lexer/string.o lexer/lexer_handle_operator.o lexer/lexer_handle_word.o \
	lexer/lexer_print_tokens.o lexer/lexer_push_token.o \
	lexer/lexer_skip_whitespaces.o lexer/util.o lexer/token_helpers.o \
	lexer/lexer_operator_len.o lexer/lexer_add_newline_token.o \
	lexer/lexer_is_word_complete.o \
	parse_complete_commands/add_complete_cmd.o \
	parse_complete_commands/cmd_tokens_helpers.o \
	parse_complete_commands/parse_complete_commands.o \
	parse_and_or/parse_and_or.o parse_and_or/add_cmd.o \
	parse_pipe/parse_pipe.o parse_pipe/add_simple_cmd.o \
	parse_simple_cmd/parse_argument.o parse_simple_cmd/parse_assignment.o \
	parse_simple_cmd/parse_redirection.o parse_simple_cmd/simple_advance.o \
	parse_simple_cmd/parse_simple_cmd.o parse_simple_cmd/parse_here_document.o \
	parse_simple_cmd/parse_word.o \
	parser.o get_job_name.o parser_helpers.o

OBJS = $(addprefix $(OBJS_DIR)/, ${PARSER})

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

.PHONY: all clean fclean re libft force
