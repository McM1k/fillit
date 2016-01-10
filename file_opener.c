/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:07:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/10 18:41:24 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int		file_opener(char *source, char *buf)
{
	int		fd;
	int		ret;

	if ((fd = open(source, O_RDONLY)) == -1)
	{
		ft_putendl("\n --- Can't open file ! ---\n");
		return (-1);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret > 545 || ret == -1)
	{
		if (ret > 545)
			ft_putendl("\n --- File too long ! ---\n");
		else
			ft_putendl("\n --- Can't read file ! ---\n");
		return (-1);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_putendl("\n --- Can't close file ! ---\n");
		return (-1);
	}
	ft_putendl(buf);
	return (ret);
}

static int		fill_tetri(t_tetr **start, char *buf)
{
	t_tetr	*current;
	char	*tmp;
	int		nb;

	tmp = buf;
	if ((nb = new_list(tmp, start)) == -1)
		return (-1);
	current = *start;
	while (nb && current)
	{
	/*	if (!check_next(current->tetrimino)
			&& !check_next2(current->tetrimino)
			&& !check_size_tetri(current->tetrimino))
		{
			ft_putendl("\n --- Error tetrimino ! --- \n");
			return (-1);
		}*/
		current = current->next;
		nb--;
	}
	return (nb);
}

static int		init_buf(char *source, char *buf)
{
	int		size;

	if ((size = file_opener(source, buf)) == -1)
		return (-1);
	if (!check_symbols(buf, size))
	{
		ft_putendl("\n --- Error symbols ! --- \n");
		return (-1);
	}
	if (!check_size(buf, size))
	{
		ft_putendl("\n --- Error size source ! --- \n");
		return (-1);
	}
	ft_putendl("init_buf ok");
	return (size);
}

int				init_tetri(char *source, t_tetr **start)
{
	int		size;
	char	*buf;
	int		nb;

	buf = (char *)ft_memalloc(sizeof(BUF_SIZE));
	if ((size = init_buf(source, buf)) == -1)
		return (-1);
	if ((nb = fill_tetri(start, buf)) == -1)
		return (-1);
	ft_memdel((void **)&buf);
	ft_putendl("init_tetri ok");
	return (nb);
}
