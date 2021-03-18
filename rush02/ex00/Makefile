SRCS	= ./srcs/main.c				\
		 ./srcs/get_dic.c			\
		  ./srcs/utils.c				\
		  ./srcs/parse_file.c			\
		  ./srcs/print_nb.c			\
		  ./srcs/free_dic.c			\
		  ./srcs/print_unity.c		\
		  ./srcs/valid.c

INCDIR	=./includes/

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
	${CC} -c ${CFLAGS} -I ${INCDIR} -o $@ $<

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
