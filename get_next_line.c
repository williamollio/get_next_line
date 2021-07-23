/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:12:48 by wollio            #+#    #+#             */
/*   Updated: 2021/07/23 16:51:15 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 8

char *get_next_line(int fd)
{

	char *a;
	static char *b;
	int i;

	i = 0;
	if (fd < 0)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!a)
		return (NULL);
	read (fd, a, BUFFER_SIZE);
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\n')
	{
		b = (char *)malloc(sizeof(char) * (i));
		if (!b)
			return (NULL);
		b = ft_substr(a, 0, i);
	}

	// b = ft_strchr(a, '\n');
	return (b);
}

int main()
{
	int fd;
	fd = open("fd.txt", O_RDONLY);
	if (fd < -1)
	{
		printf("%s", "########## Couldn't open file ##########");
		return (1);
	}
	printf("get next line : %s\n", get_next_line(fd));
	close(fd);
}
