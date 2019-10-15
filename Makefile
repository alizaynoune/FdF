# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 13:48:59 by zamazzal          #+#    #+#              #
#    Updated: 2019/09/27 15:29:44 by zamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
FLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/
OBJ_PATH = obj/
LIBFT_PATH = libft/
HEADER_PATH = includes/

LIBFT = -L $(LIBFT_PATH) -lft
INCLUDES = -I $(HEADER_PATH) -I $(LIBFT_PATH)
MLX_LIB = -lmlx -framework OpenGL -framework AppKit

SRCS_FILES =	check.c 		\
				design.c 		\
				drow.c 			\
				main.c 			\
				read.c 			\
				tools.c 		\
				events.c		\
				iso.c			\
				normal.c		\
				get_next_line.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(MLX_LIB) -o $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\x1B[96mObjects Files \x1B[90;0m[\x1B[34;1m $(notdir $(OBJ)) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re: fclean all

.PHONY: all, clean, fclean, re