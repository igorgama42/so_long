# NAME
NAME = so_long

# SOURCES
SRCS = teste_minilibx.c

# SOURCES OBJECTS
SRCS_OBJS = ${SRCS:.c=.o}

# HEADER
HDR = so_long.h

# COMPILER
CC = gcc

# COMPILER FLAGS
C_FLAGS = -Wall -Wextra -Werror

# REMOVER
RM = rm -f

# MLX_FLAGS
M_FLAGS = -lX11 -lXext ./minilibx_linux/libmlx.a #minilibx_linux/libmlx.a -framework OpenGL -framework Appkit -o $(NAME)

.c.o:
	${CC} ${C_FLAGS} -c $< -o $@ $(<:.c=.o)

all : ${NAME}

${NAME} : ${SRCS_OBJS} 
	${CC} ${C_FLAGS} -o $@ $^

clean: 
	${RM} ${SRCS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

