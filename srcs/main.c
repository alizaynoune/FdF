/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:32 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/19 14:19:05 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_openfile(char *name)
{
	int fd;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		perror("fdf");
		return (-1);
	}
	if (ft_checkvalid(name))
		return (-1);
	return (fd);
}

int				main(int argc, char **argv)
{
	int *tab;
	int fd;

	if (argc != 2 && argc != 4)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		exit(0);
	}
	SAFE(tab = check_sizes(argv[2], argv[3]));
	if ((fd = ft_openfile(argv[1])) != -1)
	{
		ft_readdata(fd, tab);
		close(fd);
	}
	free(tab);
	exit(0);
}
