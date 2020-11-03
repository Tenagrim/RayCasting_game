NAME=cub3d
PRINTF = ft_printf/libftprintf.a
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES = $(SRC_DIR)*.c
FLAGS = -Wall -Wextra -Werror -Iincludes/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
CC= gcc $(FLAGS)

all :  $(NAME)

$(PRINF) :
	$(MAKE) -C ft_printf

$(NAME) : $(LIBFT) $(PRINTF) $(SRC_FILES) $(HEADER)
	$(CC) -o $(NAME) $(SRC_FILES) $(LIBFT) $(PRINTF)

clean :
	rm -f src/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all




