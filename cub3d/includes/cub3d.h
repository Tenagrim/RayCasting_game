#ifndef CUB_3D
# define CUB_3D
# include <unistd.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>

# define _USE_MATH_DEFINES

# define KEYS_W 119
# define KEYS_A 97
# define KEYS_S 115
# define KEYS_D 100
# define KEYS_ESC 53
# define KEYS_MINUS 45
# define KEYS_PLUS 61
# define WIN_NAME "Cub3D"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17


typedef struct			s_intpair
{
	int					x;
	int					y;
}						t_intpair;


typedef struct			s_floatpair
{
	float					x;
	float					y;
}						t_floatpair;

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

typedef struct			s_map
{
	size_t				win_width;
	size_t				win_height;
	char				**map;
	t_intpair			*map_size;
}						t_map;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_map				*map;
	t_img				img;
}						t_mlx;

typedef struct			s_player
{
	t_floatpair			*pos;
	t_floatpair			*move;
	float				move_speed;
	float				rot_speed;
}						t_player;

typedef struct			s_settings
{
	float				fov;
	int					numrays;
	float				depth;
	t_intpair			win_size;
}						t_settings;

typedef struct			s_game
{
	t_map				*map;
	t_mlx				*mlx;
	t_player			*player;
	t_settings			*settings;
}						t_game;

t_list					*ft_read_file(char *filename);
void					ft_print_file(t_list *file);
t_intpair				*ft_new_intpair(int x, int y);
t_floatpair		*ft_new_floatpair(float	x, float y);
t_map					*ft_get_map_from_file(t_list *file);

int						key_press(int keycode, t_game *game);
int						key_release(int keycode, t_game *game);
int						exit_game(t_game *game, int code);
int						exit_hook(t_game *game);
int		ft_main_loop(t_game *game);
void update_window(t_game *game);

#endif
