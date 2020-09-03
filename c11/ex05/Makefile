.PHONY:	all clean fclean re

NAME	= do-op
SRCS	= $(addprefix ${FOLDER}/, main.c operations.c utils.c) 
FOLDER	= srcs
HEADERS	= includes
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			${CC} -c ${CFLAGS} $< -o $@ -I ${HEADERS}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
