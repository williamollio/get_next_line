/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:29 by wollio            #+#    #+#             */
/*   Updated: 2021/08/01 16:43:51 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char *ft_return(char **buffer, int count)
{
	int		i;
	char	*line;
	char	*tmp;

	if (count == 0)
		return (NULL);
	i = 0;
	while ((*buffer)[i] != '\n') // when buffer[i] == '\0' ??
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	tmp = ft_substr(*buffer, i + 1, count - i + 1);
	free(*buffer);
	*buffer = tmp;
	free(tmp);
	printf("buffer %p, tmp %p, line %p\n", buffer, tmp, line);
	return (line);
}

void ft_append(char **buffer, char *buff)
{
	char *tmp;

	tmp = ft_strjoin(*buffer, buff);
	free(*buffer);
	*buffer = tmp;
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buff; //to malloc
	int			bytes;
	int			count;

	count = -1;
	bytes = 1;
	if (!fd)
		return (NULL);
	while (bytes > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes > 0)
			buff[bytes] = '\0';
		else //(bytes == -1)
			return (NULL);
		if (!buffer)
			buffer = ft_strdup(buff);
		else
			ft_append(&buffer, buff);
		if (ft_strchr(buff, '\n'))
			break;
		count += bytes;
	}
	return (ft_return(&buffer, count));
}

// int main()
// {

// 	int fd;
// 	int i;
// 	int line;

// 	line = 1;
// 	i = 1;
// 	fd = open("fd.txt", O_RDONLY);
// 	if (fd < 1)
// 		printf("%s", "###### Couldn't open file ######");

// 	while (i <= line)
// 	{
// 		printf("Call %d of get next line : %s\n",i ,  get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	// system("leaks get_next_line");
// 	// fscanf(stdin, "c");
// 	return (0);
// }
