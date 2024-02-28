# MINILIBX PATH
MINILIBX_PATH = ./libraries/minilibx

# MINILIBX
MINILIBX	  = ${MINILIBX_PATH}/libmlx.a

# LIBFT PATH
LIBFT_PATH		=	./libraries/libft

# LIBFT
LIBFT			=	${LIBFT_PATH}/libft.a

# SOURCE FILES
SOURCES	 =	so_long.c game_initializer.c map_maker.c
SOURCES +=  game_design.c image_changer.c map_validations.c
SOURCES +=  gameplay.c game_closer.c

# OBJECT FILES
OBJECTS = $(SOURCES:.c=.o)

# NAME OF THE PROGRAM
NAME = so_long

# COMPILER
CC = clang

# REMOVER
RM = rm -f

# COMPILER FLAGS
CFLAGS = -Wall -Wextra -Werror

# MINILIBX FLAGS
MLX_FLAGS = -L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) so_long.h
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft
