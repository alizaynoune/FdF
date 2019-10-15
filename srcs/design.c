/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:01:33 by alzaynou          #+#    #+#             */
/*   Updated: 2019/09/27 17:22:41 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_all	ft_getspace(t_all data)
{
	int x;
	int y;

	x = (data.res.x_size - (data.res.x_size / 10) - data.size.x_size);
	y = (data.res.y_size - (data.res.y_size / 10) - data.size.y_size);
	x = x / data.size.x_size;
	y = y / data.size.y_size;
	data.space = (y <= x) ? y : x;
	if (data.space <= 1)
	{
		if (y <= x)
			data.res.y_size += 100;
		else
			data.res.x_size += 100;
		data = ft_getspace(data);
	}
	if ((X_RES_MAX > data.res.x_size + 100) &&
	(Y_RES_MAX > data.res.y_size + 100) && data.space < 10)
	{
		data.res.y_size += 100;
		data.res.x_size += 100;
		data = ft_getspace(data);
	}
	return (data);
}

static t_all	ft_calculsize(t_all data, int space)
{
	data.space = (space != 0) ? space : -1;
	if (data.space == -1)
	{
		data = ft_getspace(data);
	}
	else
	{
		while (data.space * data.size.x_size > data.res.x_size ||
		data.res.x_size < X_RES_MIN)
			data.res.x_size += 100;
		while (data.space * data.size.y_size > data.res.y_size ||
		data.res.y_size < Y_RES_MIN)
			data.res.y_size += 100;
	}
	return (data);
}

static void		ft_openwin(t_all data)
{
	void	*ptr;
	int		rx;
	int		ry;

	data.mlx = mlx_init();
	rx = data.res.x_size + 100;
	ry = data.res.y_size + 100;
	data.win = mlx_new_window(data.mlx, rx, ry, "FdF");
	data.len.x_size = (data.res.x_size / 2);
	data.len.y_size = (data.res.y_size / 10) + (data.the_long * data.space);
	data.add = 0;
	data = ft_iso(data, 0);
	ptr = &data;
	mlx_hook(data.win, 2, 0, put_key, ptr);
	mlx_loop(data.mlx);
}

static void		ft_puthelp(void)
{
	ft_putstr(YELLOW);
	ft_putstr("Space");
	ft_putstr(BLUE);
	ft_putendl(" : Change Projection mode");
	ft_putstr(YELLOW);
	ft_putstr("+/-");
	ft_putstr(BLUE);
	ft_putendl(" : Zoom");
	ft_putstr(YELLOW);
	ft_putstr("Arrow keys");
	ft_putstr(BLUE);
	ft_putendl(" : Move");
	ft_putstr(YELLOW);
	ft_putstr("Page UP/Down");
	ft_putstr(BLUE);
	ft_putendl(" : Scale UP/Scal Down");
	ft_putstr(YELLOW);
	ft_putstr("SHIFT");
	ft_putstr(BLUE);
	ft_putendl(" : Reverse");
	ft_putstr(YELLOW);
	ft_putstr("ESC");
	ft_putstr(BLUE);
	ft_putendl(" : Exit");
	ft_putstr(DEFAULT);
}

void			ft_design(t_all data, int space)
{
	data.res.x_size = X_RES_MIN;
	data.res.y_size = Y_RES_MIN;
	data = ft_calculsize(data, space);
	ft_puthelp();
	ft_openwin(data);
	mlx_destroy_window(data.mlx, data.win);
}
