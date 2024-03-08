NAME = so_long

FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext
#-fsanitize=address -g 
SRC = so_long.c map.c actions.c helper_functions.c utils.c check_map.c utils2.0.c utils3.0.c

OBJ = $(SRS:.c=.o)

MLX_DIR = ./minilibx-linux

MLX = ../minilibx-linux/libmlx.a
FT_PRINTF = ../lib/libftprintf/libftprintf.a
PRINTF_DIR =../lib/libftprintf


all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	ar rc $(NAME) $(OBJ)
	cc $(MLX_FLAGS) $(FLAGS) $(SRC) -o $(NAME) $(MLX) $(FT_PRINTF) 
	rm -rf $(NAME).o

$(MLX):	
	make -C $(MLX_DIR)
$(FT_PRINTF):
	make -C $(PRINTF_DIR)



clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus