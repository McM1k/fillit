/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/08 21:31:08 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetr	*start;
	int		nb;
	int		i;
	int		j;

	start = NULL;
	if (argc == 2)
	{
		nb = init_tetri(argv[1], start);
		while (nb)
		{
			i = 0;
			while (i < 4)
			{
				j = 0;
				while (j < 4)
				{
					ft_putchar(start->tetrimino[i][j]);
					j++;
				}
				ft_putchar('\n');
				i++;
			}
			ft_putchar('\n');
			nb--;
		}
	}
	return (0);
}
