/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:12:48 by wollio            #+#    #+#             */
/*   Updated: 2021/07/25 11:57:13 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{

	static char	*buffer;
	char		*buffer1;
	char		*line;
	int			i;
	size_t		bytes;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read (fd, buffer, BUFFER_SIZE);

	/* if error occurs during the read */
	if (bytes < 0)
		return (NULL);

	/* if nothing to read : we are at the end of the .txt */
	if (bytes == 0)
		return (0);

	while (buffer[i] && buffer[i] != '\n')
		i++;

	/* if newline contained in the buffer read */
	if (buffer[i] == '\n')
	{
		line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
		{
			free(buffer);
			return (NULL);
		}
		line = ft_substr(buffer, 0, i);
		free(buffer);
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
		buffer = ft_substr(buffer, i + 1, BUFFER_SIZE - i);
		return (line);
	}

	/* no newline in the buffer just read */
	else
	{
		while (!ft_strchr(buffer, '\n'))
		{
			buffer1 = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
			read (fd, buffer1, BUFFER_SIZE);
			buffer = ft_strjoin(buffer, buffer1);
		}
		return (buffer);
	}

}

int main()
{
	int fd;
	int line;
	int i;

	i = 1;
	line = 2;
	fd = open("fd.txt", O_RDONLY);
	if (fd < -1)
	{
		printf("%s", "########## Couldn't open file ##########");
		return (1);
	}
	while (i <= line)
	{
		printf("Call %d : get next line : %s\n", i , get_next_line(fd));
		i++;
	}
	close(fd);
}
