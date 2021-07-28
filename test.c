/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:59:08 by wollio            #+#    #+#             */
/*   Updated: 2021/07/28 10:43:59 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dst == NULL) && ((src) == NULL))
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, ((char *)s1), i);
	s2[i] = '\0';
	return (s2);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (y < ft_strlen(s2))
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
	return (s3);
}

char *ft_append(char **buffer, char *buff)
{
	char *tmp;

	tmp = ft_strjoin(*buffer, buff);
	free(*buffer);
	*buffer = tmp;
	return (*buffer);
}

int main()
{
	char *buffer;
	char *buff;

	buffer = ft_strdup("hallo");
	buff = ft_strdup(" wie geht's");
	ft_append(&buffer, buff);
	printf("%s", buffer);
}
