/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:29 by wollio            #+#    #+#             */
/*   Updated: 2021/07/28 11:46:47 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 2

char *ft_return(char *buffer, char *buff, size_t count)

{
	int i;
	char *line;

	i = 0;
	if (count == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (ft_strchr(buff, '\n'))
		return (buff);
	while (buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char *), (i + 1));
	line = ft_substr(buffer, 0, i + 1);
	buffer = calloc(sizeof(char *), count - i + 1);
	buffer = ft_substr(buffer, i + 2, count - i + 1);
	return (buffer);
}

void ft_append(char **buffer, char *buff)
{
	char *tmp;
	tmp = ft_strjoin(*buffer, buff);
	free(*buffer);
	*buffer = tmp;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		buff[BUFFER_SIZE + 1];
	int			bytes;
	int			count;

	count = 0;
	bytes = 0;
	if (!fd)
	{
		free(buffer);
		return (NULL);
	}

	while (bytes > 0)
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes >= 0) // when bytes == 0 ?
			buff[bytes] = '\0';
		else if (bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (!buffer)
			buffer = ft_calloc(bytes, sizeof(char*));
		else
			ft_append(&buffer, buff);
		if (ft_strchr(buff, '\n'))
			break;
		count += bytes;
	}
	return (ft_return(buffer, buff, count));
}

int main()
{

	int fd;
	int i;
	int line;

	line = 1;
	i = 1;
	fd = open("fd.txt", O_RDONLY);
	if (fd < 1)
		printf("%s", "###### Couldn't open file ######");

	while (i <= line)
	{
		printf("Call %d of get next line : %s\n",i ,  get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
