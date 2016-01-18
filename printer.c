/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:32:19 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/18 15:13:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**tabnew(int size)
{
	char	**tab;
	int		i;

	if (!(tab = (char **)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	return (tab);
}

static char	**dot_filler(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	ft_putnbr(size);
	ft_putendl("");
	while (i < size)
	{
		ft_putnbr(i);
		j = 0;
		ft_putendl("mdr");
		while (j < size)
		{
			ft_putnbr(j);
			ft_putendl("mdr2");
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

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

void		printer(t_tetr *ptr, int size)
{
	int		i;
	int		j;
	char	**tab;

	tab = tabnew(size);
	ft_putendl("plantage-1");
	dot_filler(tab, size);
	ft_putendl("plantage0");
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
		ft_putendl("plantage1");
		ptr = ptr->next;
		ft_putendl("plantage2");
	}
	free_tab(tab);
}
