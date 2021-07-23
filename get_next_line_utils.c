/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:15:12 by wollio            #+#    #+#             */
/*   Updated: 2021/07/23 16:51:37 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (NULL);
	while (start < ft_strlen(s) && len--)
		s1[i++] = s[start++];
	s1[i] = '\0';
	return (s1);
}
