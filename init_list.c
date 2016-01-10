/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 18:48:18 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/10 20:50:21 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetr	*fill_node(char *buf, t_tetr *new)
{
	int	i;
	int	j;

	ft_putendl(buf);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putendl("test1");
			ft_putendl(buf);
			new->tetrimino[i][j] = *buf;
			buf++;
			j++;
			ft_putendl("test2");
			ft_putendl(buf);
		}
		buf++;
		i++;
	}
	ft_putendl(buf);
	return (new);
}

static t_tetr	*new_node(char *buf)
{
	t_tetr	*new;
	int		i;

	if (!(new = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
		return (NULL);
	if (!(new->tetrimino = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (NULL);
	i = 0;
	ft_putendl(buf);
	while (i < 4)
	{
		if (!(new->tetrimino[i] = ft_strnew(4)))
			return (NULL);
		i++;
	}
	ft_putendl(buf);
	return (fill_node(buf, new));
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

int				new_list(char *buf, t_tetr **start)
{
	int		nb;
	int		i;

	if ((nb = nb_tetri(buf)) == -1)
	{
		ft_putendl("\n --- Error tetrimino  file ! ---\n");
		return (-1);
	}
	*start = new_node(buf);
	i = 1;
	while (i < nb)
	{
		(*start)->next = new_node(buf);
		if (*buf == '\n')
			buf++;
		(*start)->nbr = 'A' + i;
		*start = (*start)->next;
		i++;
	}
	(*start)->next = NULL;
	return (nb);
}
