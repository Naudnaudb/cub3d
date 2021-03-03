NAME	=	libft.a

SRCS	= 	$(wildcard srcs/*.c)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

FO		=	${SRCS:.c=.o}

FO_B	=	${SRCS_B:.c=.o}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

bonus:		all

${NAME}:	${FO}
			ar -vcrs ${NAME} ${FO}
			rm -f ${FO}

clean:
			rm -f ${FO}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean re
