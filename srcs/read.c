/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:09:43 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/26 21:08:44 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mylist	*ft_putcorr(t_mylist *new, char **tab, int *len)
{
	size_t	size;
	int		i;
	int		val;

	size = 0;
	while (tab[size])
		size++;
	SAFE(new->line = (int *)malloc(sizeof(int) * size));
	new->n_index = size;
	i = 0;
	while (tab[i])
	{
		val = ft_atoi(tab[i]);
		new->line[i] = val;
		if (*len < val)
			*len = val;
		ft_strdel(&tab[i++]);
	}
	new->prev = NULL;
	new->next = NULL;
	free(tab);
	return (new);
}

static t_mylist	*ft_add_element(t_mylist *head, char **tab, int *len)
{
	t_mylist	*tmp;
	t_mylist	*new;
	int			max;

	SAFE(new = (t_mylist *)malloc(sizeof(t_mylist)));
	if (!(new = ft_putcorr(new, tab, &max)))
	{
		free(new);
		return (NULL);
	}
	*len = max;
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
	new->n_index = tmp->n_index;
	return (head);
}

void			ft_readdata(int fd, int space)
{
	char		*line;
	char		**tab;
	t_all		data;
	int			len;

	data.head = NULL;
	data.size.y_size = 0;
	data.the_long = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		data.size.y_size++;
		if (!(data.head = ft_add_element(data.head, tab, &len)))
			return ;
		if (data.the_long < len)
			data.the_long = len;
	}
	data.size.x_size = data.head->n_index;
	data.size.y_size += data.the_long;
	data.mode = 0;
	ft_design(data, space);
	ft_freelist(data.head);
}
