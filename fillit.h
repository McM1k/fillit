/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:37:38 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/08 19:41:41 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define BUF_SIZE 546

typedef struct		s_tetr
{
	char			**tetrimino;
	int				x;
	int				y;
	char			nbr;
	struct s_tetr	*next;
}					t_tetr;


t_tetr				*init_tetri(char *source);
int					new_list(char *buf, t_tetr *start);
int					check_symbols(char *buf, int size);
int					check_size(char *buf, int size);
int					check_size_tetri(char **tetri);
int					check_next(char **tetri);
int					check_next2(char **tetri);
#endif
