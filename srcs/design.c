/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:36:18 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/19 19:13:20 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getlongz(t_mylist *head)
{
	int l;
	size_t i;
	t_mylist *tmp;

	l = 0;
	tmp = head;
	while (tmp)
	{
		i = 0;
		while (i < tmp->n_index)
		{
			if (l < tmp->line[i])
				l = tmp->line[i];
			i++;
		}
		tmp = tmp->next;
	}
	return (l);
}

int		ft_getspace(int x_size, int y_size)
{
	int x;
	int y;
	int space;

	x = (MAX_X - 100 - x_size);
	x = x / x_size;
	y = (MAX_Y - 100 - y_size);
	y = y / y_size;
	space = (y <= x) ? y : x;
	if (space <= 5)
		return (5);
	if (space >= 10)
		return (10);
	return (space);
}

void	ft_design(t_mylist *head, int *cor, t_size size)
{
	void *mlx_in;
	void *win_mlx;
	int space;

	space = ft_getspace(size.x_size, size.y_size + ft_getlongz(head));
	printf("%d\n", space);
	size.x_size = size.x_size * space;
	size.y_size = size.y_size * space + (ft_getlongz(head) * space);
	size.x_size = (size.x_size > MAX_X) ? MAX_X : size.x_size;
	size.y_size = (size.y_size > MAX_Y) ? MAX_Y : size.y_size;
	mlx_in = mlx_init();
	win_mlx = mlx_new_window(mlx_in, size.x_size, size.y_size, "FdF");
	mlx_loop(mlx_in);
	cor = NULL;
	head = NULL;
}
