# NAME
NAME = so_long

# X11 AND MLX HEADER FILES
INCLUDES = -I/usr/include -Imlx

# MINILIBX PATH
MINILIBX_PATH = minilibx_linux

# MINILIBX
MINILIBX = ${MINILIBX_PATH}/libmlx.a

# SOURCES
SOURCES = main.c

# SOURCES OBJECTS
OBJS = ${SOURCES:.c=.o}

# HEADER
HDR = so_long.h

# COMPILER
CC = clang

# COMPILER FLAGS
C_FLAGS = -Wall -Wextra -Werror

# MLX FLAGS
MLX_FLAGS = -lX11 -lXext -lmlx -Lmlx -L/usr/lib/x11

# REMOVER
RM = rm -f

.c.o:
	${CC} ${C_FLAGS} -c -o $@ $< ${INCLUDES}

all : ${NAME}

${NAME} : ${MINILIBX} ${OBJS} ${HEADER}
	${CC} ${C_FLAGS} ${MLX_FLAGS} ${OBJS} ${MINILIBX} -o ${NAME}

${MINILIBX}:
	${MAKE} -C ${MINILIBX_PATH}

clean: 
	${MAKE} -C ${MINILIBX_PATH} clean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re minilibx

