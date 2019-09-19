#!/bin/sh
make -C libft re
gcc -Wall -Wextra -Werror srcs/*.c -I libft/ -I includes -I gnl libft/libft.a gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit -o fdf
