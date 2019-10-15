/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:38:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 14:45:55 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_space(int key, int space)
{
	if (space > 0)
	{
		if (key == PLUS)
			space += 5;
		if (key == MOIN)
		{
			if (space - 5 > 0)
				space -= 5;
		}
	}
	else
	{
		if (key == MOIN)
		{
			if (space + 5 < 0)
				space += 5;
		}
		if (key == PLUS)
			space -= 5;
	}
	space = (key == SHIFT) ? space * -1 : space;
	return (space);
}

static int		ft_add(int key, int add)
{
	if (key == PUP)
		add += 5;
	if (key == PDOWN)
		add -= 5;
	return (add);
}

static t_size	ft_move(int key, t_size len)
{
	if (key == LEFT)
		len.x_size -= 10;
	if (key == RIGHT)
		len.x_size += 10;
	if (key == UP)
		len.y_size -= 10;
	if (key == DOWN)
		len.y_size += 10;
	return (len);
}

static void		ft_leave(t_all data)
{
	mlx_destroy_window(data.mlx, data.win);
	ft_freelist(data.head);
	exit(0);
}

int				put_key(int key, void *param)
{
	t_all data;

	if (ft_iskey(key))
	{
		data = *(t_all*)param;
		if (key == SPACE)
			data.mode = (data.mode) ? 0 : 1;
		if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
			data.len = ft_move(key, data.len);
		if (key == PLUS || key == MOIN || key == SHIFT)
			data.space = ft_space(key, data.space);
		if (key == PUP || key == PDOWN)
			data.add = ft_add(key, data.add);
		if (key == ESC)
			ft_leave(data);
		mlx_clear_window(data.mlx, data.win);
		data = (data.mode) ? ft_normal(data) : ft_iso(data, 0);
		*(t_all*)param = data;
	}
	return (0);
}
