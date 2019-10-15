/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:13:18 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 14:46:01 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freelist(t_mylist *head)
{
	t_mylist *tmp;

	while (head)
	{
		tmp = head;
		free(head->line);
		head = head->next;
		free(tmp);
	}
}

void	ft_puterror(void)
{
	ft_putstr(YELLOW);
	ft_putstr("error : ");
	ft_putstr(RED);
	perror("");
	ft_putstr(DEFAULT);
}

int		ft_iskey(int key)
{
	if (key == SPACE)
		return (1);
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		return (1);
	if (key == PLUS || key == MOIN || key == SHIFT)
		return (1);
	if (key == ESC)
		return (1);
	if (key == PUP || key == PDOWN)
		return (1);
	return (0);
}
