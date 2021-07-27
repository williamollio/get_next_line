/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:29 by wollio            #+#    #+#             */
/*   Updated: 2021/07/27 18:34:52 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 2

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		line[BUFFER_SIZE + 1];
	//int			i;
	size_t		bytes;

	if (!fd) // < 0
	{
		free(buffer);
		return (NULL);
	}
	// while ( )
	// if (!buffer)
	// {
	// 	bytes = read (fd, buffer, BUFFER_SIZE);
	// 	if ()
	// }
	while (bytes > 0)
	{
		bytes = read (fd, line, BUFFER_SIZE);
		if (bytes >= 0) // when bytes == 0 ?
			line[BUFFER_SIZE] = '\0';
		else if (bytes < 0)
		{
			free (buffer);
			return (NULL)
		}
		if (!buffer)
			buffer = ft_strdup(line);
		if (ft_strchr(line, '\n'))


	}

	return (buffer);

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
}
