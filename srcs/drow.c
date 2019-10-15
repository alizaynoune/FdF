/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:04:19 by alzaynou          #+#    #+#             */
/*   Updated: 2019/09/27 15:18:11 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position		pos_calc(t_position p_s, int space, int h, int cnt)
{
	p_s.x0 = (cnt - 1) * space;
	p_s.x1 = p_s.x0 + space;
	p_s.y0 = h * space;
	p_s.y1 = h * space;
	return (p_s);
}

t_position		pos_calc2(t_position *p_s, int space, int h)
{
	p_s[1].x0 = p_s[0].x0;
	p_s[1].x1 = p_s[0].x0;
	p_s[1].y0 = p_s[0].y0;
	p_s[1].y1 = (h + 1) * space;
	return (p_s[1]);
}

t_position		ft_drowlastline(t_position *p_s, int space, int h, int cnt)
{
	p_s[0].x0 = (cnt - 1) * space;
	p_s[0].x1 = p_s[0].x0;
	p_s[0].y0 = h * space;
	p_s[0].y1 = (h + 1) * space;
	return (p_s[0]);
}

static void		ft_drow2(t_all data, t_position pos, t_drow drow)
{
	if (drow.dx <= drow.dy)
	{
		while (pos.y0 != pos.y1)
		{
			mlx_pixel_put(data.mlx, data.win, data.len.x_size + pos.x0,
					data.len.y_size + pos.y0, WHITE);
			drow.acm += drow.dx;
			pos.y0 += drow.stpy;
			if (drow.acm >= drow.dy)
			{
				pos.x0 += drow.stpx;
				drow.acm -= drow.dy;
			}
		}
	}
}

void			ft_drow(t_all data, t_position pos)
{
	t_drow drow;

	drow.acm = 0;
	drow.dx = pos.x1 - pos.x0;
	drow.dy = pos.y1 - pos.y0;
	drow.stpx = drow.dx >= 0 ? 1 : -1;
	drow.stpy = drow.dy >= 0 ? 1 : -1;
	drow.dx = drow.dx > 0 ? drow.dx : drow.dx * -1;
	drow.dy = drow.dy > 0 ? drow.dy : drow.dy * -1;
	if (drow.dx > drow.dy)
	{
		while (pos.x0 != pos.x1)
		{
			mlx_pixel_put(data.mlx, data.win, data.len.x_size + pos.x0,
					data.len.y_size + pos.y0, WHITE);
			drow.acm += drow.dy;
			pos.x0 += drow.stpx;
			if (drow.acm >= drow.dx)
			{
				pos.y0 += drow.stpy;
				drow.acm -= drow.dx;
			}
		}
	}
	ft_drow2(data, pos, drow);
}
