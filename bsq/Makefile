.PHONY: all clean fclean re

NAME	= bsq
FOLDER	= srcs
SRCS	= $(addprefix ${FOLDER}/, solver.c utils.c utils2.c main.c writer.c board.c)
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
			mv $(FOLDER)/*.o obj

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
