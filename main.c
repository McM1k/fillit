/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/12 14:42:45 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetr	*start;
	t_tetr	*current;
	int		nb;
	int		i;
	int		j;

	start = NULL;
	if (argc == 2)
	{
		nb = init_tetri(argv[1], &start);
		ft_putendl("De retour dans le main");
		current = start;
		while (nb > 0)
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
			if (nb > 1)
			{
				ft_putchar('\n');
				current = current->next;
			}
			nb--;
		}
	}
	return (0);
}
