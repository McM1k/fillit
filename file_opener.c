/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:07:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/06 23:10:08 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	file_opener(char *source, char *buf)
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
	return (ret);
}

t_tetr		*init_tetri(char *source)
{
	int	size;
	char	*buf;
	t_tetr	*start;

	buf = (char *)ft_memalloc(sizeof(BUF_SIZE));
	if ((size = init_buf(source, buf)) == -1)
	return (NULL);
	if (!check_next(tetri) && !check_next2(tetri) && !check_size_tetri(tetri))
	{
		ft_putendl("\n --- Error tetrimino ! --- \n");
		return (NULL);
	}
	return (start)
}

static int	init_buf(char *source, char *buf)
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
	return (size);
}
