NAME=cub3d
HEADER=includes/cub3d.h
PRINTF = ft_printf/libftprintf.a
MLX = libmlx.dylib
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES = $(SRC_DIR)*.c gnl/*.c
FLAGS = -Wall -Wextra -Werror -Iincludes/ -O3 -g #FIXME
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
CC= gcc $(FLAGS)

all :  $(NAME)

$(PRINF) :
	$(MAKE) -C ft_printf

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

$(NAME) : $(MLX) $(LIBFT) $(PRINTF) $(SRC_FILES) $(HEADER)
	$(CC) -o $(NAME) $(SRC_FILES) $(LIBFT) $(PRINTF) $(LIBS)

clean :
	rm -f src/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all




