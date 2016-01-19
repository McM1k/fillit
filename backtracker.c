/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:11:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/19 15:04:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_pos3(int x, int y, t_tetr *tetr, t_tetr *current)
{
	int		i;
	int		j;

	ft_putendl("begincheckpos3");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			//	ft_putstr("i = ");
			//ft_putnbr(i);
			//ft_putstr(", j = ");
			//ft_putnbr(j);
			//ft_putendl("");
			if (current->tetrimino[i][j] == '#')
			{
				//		ft_putstr("\n current->x + i = ");
				//ft_putnbr(current->x + i);
				//ft_putstr("\n current->y + j = ");
				//ft_putnbr(current->y + j);
				//ft_putstr("\n tetr->x + x = ");
				//ft_putnbr(tetr->x + x);
				//ft_putstr("\n tetr->y + y = ");
				//ft_putnbr(tetr->y + y);

				if ((current->x + i == tetr->x + x)
					&& (current->y + j == tetr->y + y))
				{
					ft_putendl("checkpos3 FALSE");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	ft_putendl("checkpos3 TRUE");
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
	ft_putendl("checkpos1");
	return (1);
}

static int	check_pos2(t_tetr *start, t_tetr *tetr)
{
	int		i;
	int		j;
	t_tetr	*current;

	current = start;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->tetrimino[i][j] == '#')
			{
				while (current != tetr)
				{
					if (!(check_pos3(i, j, tetr, current)))
						return (0);
					current = current->next;
				}
			}
			j++;
		}
		i++;
	}
	ft_putendl("checkpos2");
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
			tetr->x = i;
			tetr->y = j;
			if (check_pos(i, j, tetr, size) == 1
				&& check_pos2(start, tetr) == 1)
			{
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
