/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:46:41 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/05/05 21:42:57 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line(int fd)
{
	char	buffer;
	int		length;
	int		bytes;

	buffer = 0;
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, &buffer, 1);
		if (buffer != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_line(int fd)
{
	int		linecount;
	char	buffer;
	int		bytes;

	buffer = 0;
	linecount = 1;
	while (1)
	{
		bytes = read(fd, &buffer, 1);
		if (bytes < 1)
			break ;
		if (buffer == '\n')
			linecount++;
	}
	if (buffer == '1')
		linecount++;
	return (linecount);
}

void	*myfree(void *str)
{
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		rd_byte;
	int		i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 9999);
	buffer = 0;
	if (fd < 0)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
		myfree(line);
	return (line);
}
