.PHONY: all clean fclean re

NAME	= rush-02
SRCS	= $(addprefix ${FOLDER}/, main.c ft_check_arguments.c ft_string.c ft_string2.c ft_list.c ft_list2.c ft_message_error.c ft_nb_to_words.c ft_nb_to_words2.c ft_parse_dict.c ft_read_file.c)
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
