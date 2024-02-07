# OUTPUT
OUTPUT = so_long

# SOURCES
SRCS = teste_minilibx.c

# SOURCES OBJECTS
SRCS_OBJS = ${SRCS:.c=.o}

# HEADER
HDR = /minilibx_linux/mlx.h

# COMPILER
CC = cc

# COMPILER FLAGS
C_FLAGS = -Wall -Wextra -Werror

# REMOVER
RM = rm -f

# MLX_FLAGS
M_FLAGS = -lX11 -lXext -lmlx #minilibx_linux/libmlx.a -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c
	${CC} ${C_FLAGS} -I ${HDR} -Imlx_linux -03 -c $< -o $@

all : ${OUTPUT}

${OUTPUT} : ${SRCS_OBJS}
	${CC} ${C_FLAGS} -o $@ $^

clean: 
	${RM} ${SRCS_OBJS}

fclean: clean
	${RM} ${OUTPUT}

re: fclean all

.PHONY: all clean fclean re

