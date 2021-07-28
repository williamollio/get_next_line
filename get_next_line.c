/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:29 by wollio            #+#    #+#             */
/*   Updated: 2021/07/28 18:39:02 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 2

char *ft_return(char **buffer, int count)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (*buffer[i] != '\n') // when buffer[i] == '\0' ??
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	tmp = ft_substr(*buffer, i + 1, count - i + 1);
	free(*buffer);
	*buffer = tmp;
	return (line);
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

	printf("Buffer : %s\n", buffer);
	count = 0;
	bytes = 1;
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
		if(bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (!buffer)
			buffer = ft_strdup(buff);
		else
			ft_append(&buffer, buff);
		count += bytes;
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (ft_return(&buffer, count));
}

int main()
{

	int fd;
	int i;
	int line;

	line = 2;
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
