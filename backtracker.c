/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:11:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/14 21:21:26 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			how_much_tetr(t_tetr *tetr_ptr)
{
	while (tetr_ptr->next)
	{
		tetr_ptr = tetr_ptr->next;
	}
	return ((int)(tetr_ptr->nbr - 'A' + 1));
}

static int	check_pos(int x, int y, t_tetr *tetr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->tetrimino[i][j] == '#')
				if ((i + x) >= size || (j + y) >= size
					|| (i + x) < 0 || (j + y) < 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_pos2(t_tetr *start, int x, int y, t_tetr *tetr)
{
	int		i;
	int		j;
	t_tetr	*current;

	current = start;
	while (current->nbr < tetr->nbr)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (x >= 0 && y >= 0
					&& current->tetrimino[i + x][j + y] == '#'
					&& tetr->tetrimino[i + x][j + y] == '#')
					return (0);
				j++;
			}
			i++;
		}
		current = current->next;
	}
	return (1);
}

int			backtrack_tetr(t_tetr *start, t_tetr *tetr, int size)
{
	int		i;
	int		j;

	i = -3;
	while (i < size)
	{
		j = -3;
		while (j < size)
		{
			if (check_pos(i, j, tetr, size) == 1
				&& check_pos2(start, i, j, tetr) == 1)
			{
				tetr->x = i;
				tetr->y = j;
				if ((tetr->next) == NULL)
					return (1);
				if ((backtrack_tetr(start, tetr->next, size)) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
