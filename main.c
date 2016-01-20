/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/20 21:09:31 by vroussea         ###   ########.fr       */
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

static int	main_helper(int nb, t_tetr *start)
{
	int	valid;

	valid = 0;
	while (!valid)
	{
		valid = backtrack_tetr(start, start, nb);
		nb++;
	}
	if (valid == 0)
	{
		ft_putendl("\n --- Error, can't fill it ! ---\n");
		return (0);
	}
	printer(start, --nb);
	return (1);
}

int			main(int argc, char **argv)
{
	t_tetr	*start;
	int		nb;

	start = NULL;
	if (argc == 2)
	{
		if ((nb = init_tetri(argv[1], &start)) == -1)
		{
			ft_putendl("\n --- Error, aborting program ! ---\n");
			return (1);
		}
		nb = size_tab(nb);
		main_helper(nb, start);
	}
	return (1);
}
