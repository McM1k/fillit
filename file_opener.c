/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:07:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/06 19:05:26 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

char	*file_opener(char *source)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		ret;

	if ((fd = open(source, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf, BUF_SIZE)) > 545)
		return (NULL);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (buf);
}
