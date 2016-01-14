/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:32:19 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/14 21:37:37 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putendl(tab[i]);
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void **)tab);
}

void		printer(t_tetr *ptr, char **tab)
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
	free_tab(tab);
}
