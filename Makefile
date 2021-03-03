NAME	= Cub3D

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -lXext -lX11 -lm# -fsanitize=address

SRCSF	= main.c

SRCSD	= srcs/
INCL	= includes/
LIBFT	= libft/

MLX		= minilibx-linux/

SRCS	= $(addprefix ${SRCSD},${SRCSF})
OBJS	= ${SRCS:.c=.o}



.c.o :		${INCL}cub3d.h ${LIBFT}${INCL}libft.h
			${CC} ${CFLAGS} -I${LIBFT}${INCL} -I${MLX} -I${INCL} -c $< -o ${<:.c=.o}


${NAME} :	${OBJS}
			make -C ${LIBFT}
			cp ${LIBFT}libft.a ./
			make -C ${MLX}
			cp ${MLX}libmlx.a ./
			${CC} ${LINKFL} -o ${NAME} ${OBJS} libft.a libmlx.a


all :		${NAME}

clean :
			find . -type f -name "*.o" -delete

fclean :	clean
			find . -type f -name "*.a" -delete
			rm -rf ${NAME}

re :		fclean all

.PHONY :	re clean fclean