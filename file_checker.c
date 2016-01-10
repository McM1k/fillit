/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:12:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/10 19:12:45 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			check_symbols(char *buf, int size)
{
	while (size > 0)
	{
		size--;
		if ((buf[size] != '.') && (buf[size] != '#') && (buf[size] != '\n'))
			return (0);
	}
	return (1);
}

int			check_size(char *buf, int size)
{
	int			squ_x;
	int			squ_y;

	while (size >= 0)
	{
		size--;
		squ_y = 0;
		while (squ_y < 4)
		{
			squ_x = 0;
			if (buf[size] != '\n')
				return (0);
			while (squ_x < 4)
			{
				size--;
				if (size < 0 || buf[size] == '\n')
					return (0);
				squ_x++;
			}
			squ_y++;
			size--;
		}
	}
	return (1);
}

int			check_size_tetri(char **tetri)
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

int			check_next(char **tetri)
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
	if ((valid = valid + check_next2(tetri)) < 5)
		return (0)
	return (1);
}

int			check_next2(char **tetri)
{
	int			i;
	int			j;
	int			valid;

	i = 4;
	while (i > 0)
	{
		while (j > 0)
		{
			valid = 0;
			if (tetri[i][j] == '#')
			{
				if (tetri[i][j - 1] == '#')
					valid++;
				else if (tetri[i - 1][j] == '#')
					valid++;
			}
			j--;
		}
		j = 4;
		i--;
	}
	return (valid);
}
