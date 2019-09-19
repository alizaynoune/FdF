/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:09:43 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/19 14:10:34 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mylist	*ft_putcorr(t_mylist *new, char **tab)
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

static t_mylist	*ft_add_element(t_mylist *head, char **tab)
{
	t_mylist *tmp;
	t_mylist *new;

	SAFE(new = (t_mylist *)malloc(sizeof(t_mylist)));
	if (!(new = ft_putcorr(new, tab)))
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
	{
		ft_freelist(head);
		return (NULL);
	}
	return (head);
}

void			ft_readdata(int fd, int *cor)
{
	char		*line;
	char		**tab;
	t_mylist	*head;
	t_size		size;

	cor = NULL;
	head = NULL;
	size.y_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		size.y_size++;
		if (!(head = ft_add_element(head, tab)))
			return ;
		
	}
	size.x_size = head->n_index;
	ft_design(head, cor, size);
	ft_freelist(head);
}
