# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wollio <wollio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 15:57:03 by wollio            #+#    #+#              #
#    Updated: 2021/07/27 09:00:07 by wollio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c -Wall -Wextra -Werror

NAME = get_next_line.a

SOURCES = get_next_line.c \
			get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(SOURCES)
	ar cr $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
