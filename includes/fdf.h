/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:53 by zamazzal          #+#    #+#             */
/*   Updated: 2019/09/18 23:19:37 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_mylist
{
	int *line;
	size_t n_index;
	struct s_mylist	*next;
	struct s_mylist *prev;
}					t_mylist;

/*
**		Malloc Protection
*/

# define SAFE(expr) if (!(expr)) return (0)

#endif
