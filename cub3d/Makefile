.PHONY: clean fclean re bonus
NAME=cub3d
HEADER=includes/cub3d.h
PRINTF = ft_printf/libftprintf.a
MLX_MAC = libmlx.dylib
MLX_LIN = libmlx.a
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES = $(SRC_DIR)*.c gnl/*.c
FLAGS = -Wall -Wextra  -Iincludes/ -O0 -g #FIXME
INC=/usr/include #FIXME
INCLIB=$(INC)/../lib #FIXME
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
LIBS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
#CC= gcc $(FLAGS)
CC= gcc $(FLAGS) -I$(INC) #FIXME

all :  $(NAME)

$(PRINF) :
	$(MAKE) -C ft_printf

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

#$(CC) -o $(NAME) $(SRC_FILES) $(LIBFT) $(PRINTF) $(LIBS)
$(NAME) : $(MLX) $(LIBFT) $(PRINTF) $(SRC_FILES) $(HEADER)
	$(CC) -o $(NAME) $(SRC_FILES) $(LIBFT) $(MLX_LIN) $(PRINTF) -Lminilibx/ -lmlx -L /usr/lib -lXext -lX11 -lm -lbsd
clean :
	make clean -C ft_printf
	rm -f src/*.o

fclean : clean
	make re -C ft_printf
	rm -f $(NAME)

re : fclean all




