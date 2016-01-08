/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:49:22 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/08 19:13:43 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetr	*fill_node(char *buf, t_tetr *new)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new->tetrimino[i][j] = *buf;
			buf++;
		}
		buf++;
		i++;
	}
	return (new);
}

static t_tetr	*new_node(char *buf)
{
	t_tetr	*new;
	int		i;

	i = 0;
	if (!(new = (t_tetr *)ft_memalloc(sizeof(t_tetr *))))
		return (NULL);
	if (!(new->tetrimino = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (NULL);
	while (i < 4)
	{
		if (!(new->tetrimino[i] = (char *)ft_memalloc(4)))
			return (NULL);
		i++;
	}
	fill_node(buf, new);
	return (new);
}

static int		nb_tetri(char *buf)
{
	int		nb_tetri;
	int		i;

	i = 0;
	nb_tetri = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			nb_tetri++;
		i++;
	}
	if ((nb_tetri % 4) != 0)
		return (-1);
	return (nb_tetri / 4);
}

int				new_list(char *buf, t_tetr *start)
{
	t_tetr	*tmp;
	int		nb;
	int		i;

	if ((nb = nb_tetri(buf)) == -1)
	{
		ft_putendl("\n --- Error tetrimino  file ! ---\n");
		return (-1);
	}
	tmp = start;
	i = 0;
	while (i < nb)
	{
		tmp = new_node(buf);
		if (*buf == '\n')
			buf++;
		tmp->nbr = 'A' + i;
		tmp = tmp->next;
		i++;
	}
	return (nb);
}
