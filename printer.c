/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:32:19 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/14 21:15:26 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			printer(t_tetr *ptr, char **tab)
{
	int		i;
	int		j;

	while (ptr != NULL)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (ptr->tetrimino[i][j] == '#')
					tab[ptr->x + i][ptr->y + j] = ptr->nbr;
				j++;
			}
			i++;
		}
		ptr = ptr->next;
	}
}
