# NAME
NAME = so_long

# COMPILER
CC = cc

# COMPILER FLAGS
C_FLAGS = -Wall -Wextra -Werror

# MLX_FLAGS
M_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@
