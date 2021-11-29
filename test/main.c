/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:57 by wollio            #+#    #+#             */
/*   Updated: 2021/10/20 17:59:27 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int main()
{

    int fd;
    int i;
    char *line;

    i = 1;
    fd = open("text.txt", O_RDONLY);
    if (fd < 1)
        printf("%s", "###### Couldn't open file ######");
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("Call %d of get next line : %s\n", i, line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (0);
}