/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:53 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/19 17:54:45 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**		Headers
*/

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include <mlx.h>

/*
**		Macros
*/

#define WHITE 16777215
#define MAX_X 1920
#define MAX_Y 1080

/*
**		Data Structs
*/

typedef struct s_mylist
{
	int *line;
	size_t n_index;
	struct s_mylist	*next;
	struct s_mylist *prev;
}					t_mylist;

typedef struct s_size
{
	int x_size;
	int y_size;
}				t_size;

/*
**		Malloc Protection
*/

# define SAFE(expr) if (!(expr)) return (0)

/*
**		Functions Prototypes
*/

void	ft_readdata(int fd, int *cor);
int     ft_checkvalid(char *name);
int     *check_sizes(char *case_s, char *z_s);
int     ft_checklen(t_mylist *new);
void    ft_freelist(t_mylist *head);
void    ft_design(t_mylist *head, int *cor, t_size  size);

#endif
