/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:37:38 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/06 17:48:33 by gboudrie         ###   ########.fr       */
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

int					check_symbols(char *buf, int size);
int					check_size(char *buf, int size);
int					check_size_tetr(char **tetri);
int					check_is_next_to(char **tetri);
int					check_is_next_to2(char **tetri);
#endif
