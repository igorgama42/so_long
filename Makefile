# OUTPUT
OUTPUT = so_long

# SOURCES
SRCS =

# SOURCES OBJECTS
SRCS_OBJ = ${SRCS:.c=.o}

# HEADER
HDR =

# COMPILER
CC = cc

# COMPILER FLAGS
C_FLAGS = -Wall -Wextra -Werror

# MLX_FLAGS
M_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

.c.o:
	${CC} ${C_FLAGS} -I ${HDR} -Imlx_linux -03 -c $< -o $@
