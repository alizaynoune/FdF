/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:05:30 by alzaynou          #+#    #+#             */
/*   Updated: 2019/09/18 20:21:09 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "next/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
#include <stdio.h>
typedef struct s_mylist
{
	int *line;
	size_t n_index;
	struct s_mylist	*next;
	struct s_mylist *prev;
}					t_mylist;

void    ft_char_to_int(t_mylist *new, char **tab);
t_mylist    *ft_link_list(t_mylist *head, char **tab);
void    ft_check_validat(t_mylist *new);
void    ft_check_fd(const int fd, char *nume);

#endif
