/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/14 17:44:36 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	size_tab(int nb)
{
	int	size;

	nb = nb * 4;
	size = nb;
	while ((size = ft_sqrt(size)) == -1)
	{
		nb++;
		size = nb;
	}
	return (size);
}

int			main(int argc, char **argv)
{
	t_tetr	*start;
	t_tetr	*current; //
	int		nb;
	int		i; // inutils :
	int		j; //
	int		k; //

	start = NULL;
	if (argc == 2)
	{
		nb = init_tetri(argv[1], &start);
		size_tab(nb)
		current = start;
		k = nb;
		while (k > 0)
		{
			i = 0;
			while (i < 4)
			{
				j = 0;
				while (j < 4)
				{
					ft_putchar(current->tetrimino[i][j]);
					j++;
				}
				ft_putchar('\n');
				i++;
			}
			if (k > 1)
			{
				ft_putchar('\n');
				current = current->next;
			}
			k--;
		}
		//backtracker(start, tab, size_tab(nb));
	}
	return (0);
}
