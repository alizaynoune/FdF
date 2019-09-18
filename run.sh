#!/bin/sh
make -C libft re
gcc -Wall -Wextra -Werror main.c -I libft/ -I includes -I gnl libft/libft.a gnl/get_next_line.c -o fdf
