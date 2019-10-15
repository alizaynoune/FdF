/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:09:09 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 15:18:32 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_applyl(t_mylist *temp, t_all data, size_t cnt, int h)
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
		ft_drow(data, temp->p_s[0]);
	}
}

t_all			ft_normal(t_all data)
{
	size_t		cnt;
	int			h;
	t_mylist	*temp;

	h = 0;
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
				ft_drow(data, temp->p_s[1]);
			}
			ft_drow(data, temp->p_s[0]);
			cnt++;
		}
		ft_applyl(temp, data, cnt, h);
		h++;
		temp = temp->next;
	}
	return (data);
}
