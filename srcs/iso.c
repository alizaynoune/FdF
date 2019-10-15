/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:07:26 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 15:18:52 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

static void		ft_isoapply(t_mylist *temp, int cnt, int space, int add)
{
	int z1;
	int z2;

	z1 = temp->line[cnt - 1];
	z2 = temp->next->line[cnt - 1];
	if (z1)
		z1 += add;
	if (z2)
		z2 += add;
	iso(&temp->p_s[1].x0, &temp->p_s[1].y0, z1 * space);
	iso(&temp->p_s[1].x1, &temp->p_s[1].y1, z2 * space);
}

static void		ft_isoapplyl(t_mylist *temp, t_all data, size_t cnt, int h)
{
	int z1;
	int z2;

	if (temp->next)
	{
		temp->p_s[0] = ft_drowlastline(temp->p_s, data.space, h, cnt);
		z1 = temp->line[cnt - 1];
		z2 = temp->next->line[cnt - 1];
		if (z1)
			z1 += data.add;
		if (z2)
			z2 += data.add;
		iso(&temp->p_s[0].x0, &temp->p_s[0].y0, z1 * data.space);
		iso(&temp->p_s[0].x1, &temp->p_s[0].y1, z2 * data.space);
		ft_drow(data, temp->p_s[0]);
	}
}

static void		ft_isoapply2(t_mylist *temp, int cnt, int space, int add)
{
	int z1;
	int z2;

	z1 = temp->line[cnt - 1];
	z2 = temp->line[cnt];
	if (z1)
		z1 += add;
	if (z2)
		z2 += add;
	iso(&temp->p_s[0].x0, &temp->p_s[0].y0, z1 * space);
	iso(&temp->p_s[0].x1, &temp->p_s[0].y1, z2 * space);
}

t_all			ft_iso(t_all data, int h)
{
	size_t		cnt;
	t_mylist	*temp;

	temp = data.head;
	while (temp)
	{
		cnt = 1;
		while (cnt < temp->n_index)
		{
			temp->p_s[0] = pos_calc(temp->p_s[0], data.space, h, cnt);
			if (temp->next)
			{
				temp->p_s[1] = pos_calc2(temp->p_s, data.space, h);
				ft_isoapply(temp, cnt, data.space, data.add);
				ft_drow(data, temp->p_s[1]);
			}
			ft_isoapply2(temp, cnt, data.space, data.add);
			ft_drow(data, temp->p_s[0]);
			cnt++;
		}
		ft_isoapplyl(temp, data, cnt, h);
		h++;
		temp = temp->next;
	}
	return (data);
}
