/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:13:18 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/19 14:14:39 by zamazzal         ###   ########.fr       */
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
