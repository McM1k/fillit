/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:07:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/21 15:21:24 by vroussea         ###   ########.fr       */
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
		return (-1);
	ret = read(fd, buf, BUF_SIZE);
	if (ret > 545 || ret == -1)
		return (-1);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (-1);
	return (ret);
}

static int		fill_tetri(t_tetr **start, char *buf)
{
	t_tetr	*current;
	char	*tmp;
	int		nb;
	int		i;

	tmp = buf;
	if ((nb = new_list(tmp, start)) == 0)
		return (-1);
	i = nb;
	current = *start;
	while (i)
	{
		if (!check_next(current->tetrimino)
			|| !check_size_tetri(current->tetrimino))
			return (-1);
		current = current->next;
		i--;
	}
	return (nb);
}

static int		init_buf(char *source, char *buf)
{
	int		size;

	if ((size = file_opener(source, buf)) == -1)
		return (-1);
	if (!check_symbols(buf, size))
		return (-1);
	if (!check_size(buf, size))
		return (-1);
	return (size);
}

int				init_tetri(char *source, t_tetr **start)
{
	int		size;
	char	*buf;
	int		nb;

	buf = (char *)ft_memalloc(BUF_SIZE);
	if ((size = init_buf(source, buf)) == -1)
		return (-1);
	if ((nb = fill_tetri(start, buf)) == -1)
		return (-1);
	ft_memdel((void **)&buf);
	return (nb);
}
