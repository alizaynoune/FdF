/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:20:10 by alzaynou          #+#    #+#             */
/*   Updated: 2019/09/18 20:22:33 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_validat(t_mylist *new)
{
	if (new->n_index != new->prev->n_index)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		exit (0);
	}
}

void	ft_check_fd(const int fd, char *nume)
{
	char buff[1];

	if (fd < 0)
	{
		ft_putstr("No file ");
		ft_putstr(nume);
		ft_putchar('\n');
		exit (0);
	}
	if (read(fd, buff, 0) < 0)
	{
		ft_putstr("No data found.\n");
		exit (0);
	}
}
