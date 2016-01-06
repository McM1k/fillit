/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:07:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/06 17:22:30 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*file_opener(char	*source)
{
	char	*buf;
	int		fd;

	buf = NULL;
	if ((fd = open(source, O_RDONLY)) == -1)
		return (NULL);
	return (buf);
}
