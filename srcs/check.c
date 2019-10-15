/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:11:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 14:36:43 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checklen(t_mylist *new)
{
	if (new->n_index < new->prev->n_index)
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (1);
	}
	return (0);
}

int		ft_checkvalid(char *name)
{
	int		fd;
	int		r;
	char	buff[1];

	fd = open(name, O_RDONLY);
	r = read(fd, buff, 1);
	close(fd);
	if (r == 0)
		ft_putendl("No data found.");
	else if (r < 0)
		ft_puterror();
	if (r == 0 || r < 0)
		return (1);
	return (0);
}
