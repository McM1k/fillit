/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:05:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/05 21:45:34 by gboudrie         ###   ########.fr       */
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



#endif
