/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:03:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/09/18 19:36:53 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	t_mylist	*head;

	head = NULL;
	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit (0);
	}
	fd = open(av[1] ,O_RDONLY);
	ft_check_fd(fd, av[1]);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		head = ft_link_list(head, tab);
	}
}

void	ft_char_to_int(t_mylist *new, char **tab)
{
	size_t	cnt_index0;
	int		cnt_index1;

	cnt_index0 = 0;
	cnt_index1 = 0;
	while (tab[cnt_index0])
		cnt_index0++;
	if(!(new->line = (int *)malloc(sizeof(int) * cnt_index0)))
		return ;
	new->n_index = cnt_index0;
	cnt_index0 = 0;
	while (tab[cnt_index0])
	{
		new->line[cnt_index1++] = ft_atoi(tab[cnt_index0]);
		free(tab[cnt_index0]);
		cnt_index0++;
	}
	new->next = NULL;
	new->prev = NULL;
	free(tab);
	tab = NULL;
}

t_mylist	*ft_link_list(t_mylist *head, char **tab)
{
	t_mylist *temp;
	t_mylist *new;

	temp = head;
	if (!(new = (t_mylist *)malloc(sizeof(t_mylist))))
		return (NULL);
	ft_char_to_int(new, tab);
	if (head == NULL)
		return (new);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	ft_check_validat(new);
	return (head);
}
