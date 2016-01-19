/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/19 18:02:36 by vroussea         ###   ########.fr       */
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
	int		nb;
	int		valid;

	start = NULL;
	if (argc == 2)
	{
		if ((nb = init_tetri(argv[1], &start)) == -1)
		{
			ft_putendl("\n --- Error, aborting program ! ---\n");
			return (1);
		}
		valid = 0;
		nb = size_tab(nb);
		while (!valid)
		{
			valid = backtrack_tetr(start, start, nb);
			nb++;
		}
		if (valid == 0)
		{
			ft_putendl("\n --- Error, can't fill it ! ---\n");
			return (1);
		}
		printer(start, --nb);
	}
	return (0);
}
