NAME=libftprintf.a
LIBFT = libft/*.o
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES =  	ft_format_output_char.c ft_format_output_digit.c \
		ft_format_output_str.c ft_get_attr.c ft_get_conv.c \
		ft_get_flags.c ft_get_precision.c ft_get_size.c ft_get_width.c \
		ft_ifchar.c ft_ifdigit.c ft_ifstr.c ft_itoa_base.c \
		ft_itoa_base_h.c ft_itoa_base_hh.c ft_itoa_base_l.c \
		ft_itoa_base_ll.c ft_itoa_base_u.c ft_itoa_base_uh.c \
		ft_itoa_base_uhh.c ft_itoa_base_ul.c ft_itoa_base_ull.c \
		ft_min.c ft_new_attr.c ft_print_conv.c ft_printf.c \
		ft_pow.c ft_dtoa.c ft_format_output_float.c \
		ft_iffloat.c ft_max.c ft_ifptr.c ft_abs.c
FLAGS = -Wall -Wextra -Werror -Iincludes/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
CC= gcc $(FLAGS)

all : libft $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADER)
	$(MAKE) -C libft
	ar rc $(NAME) $(OBJ_FILES) $(LIBFT)

clean :
	rm -f src/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all




