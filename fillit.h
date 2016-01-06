/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:37:38 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/06 23:01:08 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define BUF_SIZE 546

typedef struct		s_tetr
{
	char			**tetrimino;
	char			nbr;
	struct s_tetr	*next;
}					t_tetr;

char				*init_buf(char *source);
int					check_symbols(char *buf, int size);
int					check_size(char *buf, int size);
int					check_size_tetr(char **tetri);
int					check_next(char **tetri);
int					check_next2(char **tetri);
#endif
