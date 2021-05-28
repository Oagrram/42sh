# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/04/28 12:29:41 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = job_control.a


# compilation variables
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_PATH) -g
CC = gcc

42SH_ROOT=../../..

INCLUDES_PATH = $(42SH_ROOT)/includes

INCLUDES =	$(42SH_ROOT)/includes/forty_two_sh.h $(42SH_ROOT)/includes/typedefs.h \
			$(42SH_ROOT)/src/errors/errors.h

SRCS = execute_job.c \
	get_job_by_selector.c \
	get_latest_jobs.c \
	job_list.c \
	new_job.c \
	notify_jobs.c \
	print_job.c \
	process.c \
	update_job.c \
	update_stopped_jobs.c \
	wait_job.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# objects directory
OBJS_DIR = objs


# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

$(OBJS) : $(INCLUDES)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
