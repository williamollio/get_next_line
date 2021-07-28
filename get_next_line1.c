/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:12:48 by wollio            #+#    #+#             */
/*   Updated: 2021/07/28 10:00:52 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#  define BUFFER_SIZE 3

char *get_next_line(int fd)
{

	static char	*buffer;
	char buffer1[BUFFER_SIZE];
	char		*line;
	int			i;
	int			j;
	size_t		bytes;

	i = 0;
	j = 1;
	if (fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	/* check if there is already something in the static var */
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (fd < 0)
		{
			free(buffer);
			return (NULL);
		}
		/* if error occurs during the read || end .txt || .txt is empty */
		if (bytes < 0 || bytes == 0 )
		{
			free(buffer);
			return (NULL);
		}
	}
	while (buffer[i] && buffer[i] != '\n') // 123\n123
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
		free (buffer);
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
		if (!buffer)
			return (NULL);
		buffer = ft_substr(buffer, i + 1, BUFFER_SIZE - i);
		return (line);
	}

	char	*tmp;
	/* no newline in the buffer just read */
	else
	{
		line = buffer;
		while (!ft_strchr(line, '\n'))
		{
			read(fd, buffer1, BUFFER_SIZE);
			buffer1[BUFFER_SIZE + 1] = '\0';
			if (fd < 0)
			{
				free (buffer);
				return (NULL);
			}
			tmp = ft_strjoin(line, buffer1);
			free(line);
			line = tmp;
			j++;
		}
		i = 0;
		while (line[i] && line[i] != '\0')
			i++;
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE * j) + 1);
		buffer = ft_substr(line, i, BUFFER_SIZE - i + 1);
		printf("%s\n", buffer);
		line = ft_substr(line, 0, i);
		return (line);
	}
	free(buffer);
	return (NULL);
}

int main()
{
	int fd;
	int line;
	int i;

	i = 1;
	line = 1;
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
