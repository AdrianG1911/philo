# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 01:22:37 by adrgutie          #+#    #+#              #
#    Updated: 2024/11/19 22:37:43 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDLIBS		= -lpthread
RM			= rm -fr
OBJ_DIR		= obj

SRCS		= src/philo.c \
			  src/philos_init.c \
			  src/philo_utils.c \
			  src/init_thread_datas.c \
			  src/free.c \
			  src/philo_message.c \
			  src/philo_work.c \
			  src/philo_work_utils.c

OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -g -o $@
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -g -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re