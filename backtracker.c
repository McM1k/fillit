/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:11:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/08 19:40:42 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			how_much_tetr(t_tetr *tetr_ptr)
{
	while (tetr_ptr->next)
	{
		tetr_ptr = tetr_ptr->next;
	}
	return ((int)(tetr_ptr->nbr - 'A' + 1));
}

char		**backtrack_tetr(t_tetr *tetr, char **tab)
{
	int		i;
	int		j;

	i = -3;
	j = -3;
	while ()
	{

	}
}
