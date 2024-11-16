# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 01:22:37 by adrgutie          #+#    #+#              #
#    Updated: 2024/11/17 01:42:03 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -Llibft
LDLIBS		= -lft -lpthread
RM			= rm -fr
OBJ_DIR		= obj

SRCS		= src/philo.c \
			  src/philos_init.c \
			  src/philo_utils.c \
			  src/free.c

OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re