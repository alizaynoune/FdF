# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 16:41:17 by alzaynou          #+#    #+#              #
#    Updated: 2019/09/18 18:39:33 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BIN = main.o  check_validat.o get_next_line.o
SRC = main.c check_validat.c next/get_next_line.c
FLAGS = -Wall -Wextra -Werror -c
.PHONY : all clean fclean re

all: $(NAME)

$(NAME) :
	make -C next/libft/
	gcc $(FLAGS) $(SRC)
	gcc -o $(NAME) $(BIN) -L next/libft/ -lft
clean:
	rm -rf $(BIN)
	make -C next/libft clean
fclean: clean
	rm -rf $(NAME)
	make -C next/libft fclean

re : fclean all
