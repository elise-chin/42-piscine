.PHONY:	all clean fclean re

NAME	= libft.a
SRCS	= $(addprefix ${FOLDER}/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c) 
FOLDER	= srcs
HEADERS	= includes
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADERS}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
