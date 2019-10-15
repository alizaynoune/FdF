/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:32 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/27 14:45:08 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_openfile(char *name)
{
	int fd;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_puterror();
		return (-1);
	}
	if (ft_checkvalid(name))
		return (-1);
	return (fd);
}

static void			ft_usage(void)
{
	ft_putstr(YELLOW);
	ft_putstr("Usage");
	ft_putstr(RED);
	ft_putendl(" : ./fdf <filename> [ case_size ]");
	ft_putstr(DEFAULT);
}

int					main(int argc, char **argv)
{
	int fd;
	int space;

	if (argc != 2 && argc != 3)
	{
		ft_usage();
		exit(0);
	}
	space = (argv[2]) ? ft_atoi(argv[2]) : 0;
	if ((fd = ft_openfile(argv[1])) != -1)
	{
		ft_readdata(fd, space);
		close(fd);
	}
	exit(0);
}
