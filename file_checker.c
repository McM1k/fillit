/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:56:35 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/06 17:49:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			check_symbols(char *buf, int size)
{
	while (size > 0)
	{
		if ((buf[size] != '.') && (buf[size] != '#') && (buf[size] != '\n'))
			return (0);
		size--;
	}
	return (1);
}

int			check_size(char *buf, int size)
{
	int			squ_x;
	int			squ_y;

	squ_x = 0;
	squ_y = 0;
	while (size > 0)
	{
		if (squ_y == 4)
		{
			if (buf[size - 1] == '\n')
				squ_y = 0;
			else
				return (0);
		}
		else if (buf[size] == '\n')
		{
			if (squ_x == 4)
				squ_y++;
			else
				return (0);
			squ_x = 0;
		}
		size--;
	}
	return (1);
}

int			check_size_tetr(char **tetri)
{
	int			i;
	int			j;
	int			size;

	i = 0;
	size = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetri[i][j] == '#')
				size++;
			j++;
		}
		j = 0;
		i++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int			check_is_next_to(char **tetri)
{
	int			i;
	int			j;
	int			valid;

	i = 0;
	valid = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				if (tetri[i][j + 1] == '#')
					valid++;
				else if (tetri[i + 1][j] == '#')
					valid++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (valid == 4)
		return (1);
	return (0);
}

int			check_is_next_to2(char **tetri)
{
	int			i;
	int			j;
	int			valid;

	i = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			valid = 0;
			if (tetri[i][j] == '#')
			{
				if (tetri[i][j + 1] == '#')
					valid++;
				if (tetri[i + 1][j] == '#')
					valid++;
				if (valid > 1)
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
