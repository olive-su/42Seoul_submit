# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 22:49:19 by sugkim            #+#    #+#              #
#    Updated: 2021/03/18 10:40:35 by sugkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq 
CC = gcc
CFLAGS = -c -Werror -Wall -Wextra
SOURCES = src/main.c src/file_roader.c src/tools/ft_strcat.c src/tools/ft_putchar.c \
		  src/tools/ft_putstr.c src/tools/ft_atoi.c src/tools/ft_strlen.c \
		  src/tools/ft_strncat.c src/tools/ft_putnbr.c src/sorting.c \
		  src/square_finder.c src/tools/ft_map_error.c src/print_map.c
OBJ = main.o file_roader.o ft_strcat.o ft_putchar.o ft_putstr.o ft_atoi.o ft_strlen.o \
	  ft_strncat.o ft_putnbr.o sorting.o square_finder.o ft_map_error.o print_map.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I includes $(SOURCES)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f standard_in.txt

re: fclean all

.PHONY:		clean fclean re all
