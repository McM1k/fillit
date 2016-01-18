/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:11:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/18 20:05:59 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_pos3(int x, int y, t_tetr *tetr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tetr->tetrimino[i][j] == '#')
					return (0);
			i++;
		}
		j++;
	}
	return (1);
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

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->tetrimino[i][j] == '#')
			{
				
			}
			j++;
		}
		i++;
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
