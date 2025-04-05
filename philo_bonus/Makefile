# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 01:22:37 by adrgutie          #+#    #+#              #
#    Updated: 2025/04/05 22:18:08 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LDLIBS		= -lpthread
RM			= rm -fr
OBJ_DIR		= obj

SRCS		= src/philo_bonus.c \
			  src/kill_exit.c \
			  src/monitor_philo.c \
			  src/philo_bonus_utils.c \
			  src/philo_message.c \
			  src/philo_utils.c \
			  src/philos_init_name.c \
			  src/philos_init.c

OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re