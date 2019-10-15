/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:53 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 15:28:07 by zamazzal         ###   ########.fr       */
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
# include <math.h>

/*
**		Macros
*/

# define WHITE 0xffffff

# define X_RES_MIN 640
# define Y_RES_MIN 480

# define X_RES_MAX 2460
# define Y_RES_MAX 1295

# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MOIN 78
# define ESC 53
# define SHIFT 257
# define PUP 116
# define PDOWN 121

# define DEFAULT "\033[0m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define GRAY "\033[90;1m"

/*
**		Data Structs
*/

typedef struct		s_drow
{
	int dx;
	int dy;
	int acm;
	int stpx;
	int stpy;
}					t_drow;

typedef struct		s_position
{
	int x0;
	int x1;
	int y0;
	int y1;
}					t_position;

typedef struct		s_mylist
{
	int				*line;
	size_t			n_index;
	t_position		p_s[2];
	struct s_mylist	*next;
	struct s_mylist	*prev;
}					t_mylist;

typedef struct		s_size
{
	int	x_size;
	int	y_size;
}					t_size;

typedef struct		s_all
{
	t_mylist	*head;
	t_size		size;
	t_size		res;
	t_size		len;
	void		*mlx;
	void		*win;
	int			the_long;
	int			space;
	int			mode;
	int			add;
}					t_all;

/*
**		Malloc Protection
*/

# define SAFE(expr) if (!(expr)) return (0)

/*
**		Functions Prototypes
*/

int					put_key(int key, void *param);
int					ft_iskey(int key);

void				ft_readdata(int fd, int space);

int					ft_checkvalid(char *name);
int					*check_sizes(char *case_s, char *z_s);
int					ft_checklen(t_mylist *new);

void				ft_design(t_all data, int space);
t_position			ft_drowlastline(t_position *p_s, int space, int h, int cnt);
void				ft_drow(t_all data, t_position pos);
t_all				ft_normal(t_all data);
t_all				ft_iso(t_all data, int h);

t_position			pos_calc(t_position p_s, int space, int h, int cnt);
t_position			pos_calc2(t_position *p_s, int space, int h);

void				ft_puterror();
void				ft_freelist(t_mylist *head);
#endif
