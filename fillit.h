/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:37:38 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/06 17:38:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct		s_tetr
{
	char			**tetrimino;
	char			nbr;
	struct s_tetr	*next;
}					t_tetr;

static int			check_symbols(char *buf, int size);
static int			check_size(char *buf, int size);
static int			check_size_tetr(char **tetri);
static int			check_is_next_to(char **tetri);
static int			check_is_next_to2(char **tetri);
#endif
