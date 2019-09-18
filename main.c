/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:32 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/18 23:40:48 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checklen(t_mylist *new)
{
	if (new->n_index != new->prev->n_index)
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (1);
	}
	return (0);
}

int		*check_sizes(char *case_s, char *z_s)
{
	int *tab;

	SAFE(tab = (int *)malloc(sizeof(int) * 2));
	if (case_s == NULL || z_s == NULL)
	{
		tab[0] = 0;
		tab[1] = 0;
		return (tab);
	}
	tab[0] = ft_atoi(case_s);
	tab[1] = ft_atoi(z_s);
	if (tab[0] == 0 || tab[1] == 0)
	{
		tab[0] = 0;
		tab[1] = 0;
	}
	return (tab);
}

t_mylist	*ft_char_to_int(t_mylist *new, char **tab)
{
	size_t	size;
	int		i;

	size = 0;
	while (tab[size])
		size++;
	SAFE(new->line = (int *)malloc(sizeof(int) * size));
	new->n_index = size;
	i = 0;
	while (tab[i])
	{
		new->line[i] = ft_atoi(tab[i]);
		ft_strdel(&tab[i++]);
	}
	new->prev = NULL;
	new->next = NULL;
	free(tab);
	return (new);
}

t_mylist	*ft_add_element(t_mylist *head, char **tab)
{
	t_mylist *tmp;
	t_mylist *new;

	SAFE(new = (t_mylist *)malloc(sizeof(t_mylist)));
	if (!(new = ft_char_to_int(new, tab)))
	{
		free(new);
		return (NULL);
	}
	if (head == NULL)
		return (new);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	if (ft_checklen(new))
		return (NULL);
	return (head);
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
		perror("fdf");
	if (r == 0 || r < 0)
		return (1);
	return (0);
}

int		ft_openfile(char *name)
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

void	ft_readdata(int fd, int *cor)
{
	char		*line;
	char		**tab;
	t_mylist	*head;

	cor = NULL;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		head = ft_add_element(head, tab);
	}
}

int		main(int argc, char **argv)
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
		ft_readdata(fd, tab);
	close(fd);
	free(tab);
	exit(0);
}
