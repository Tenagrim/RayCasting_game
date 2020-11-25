#ifndef CUB_3D
# define CUB_3D
# include <unistd.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>
# include <keys_lin.h>
# define _USE_MATH_DEFINES

# define WIN_NAME "Cub3D"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17
# define MOVE_FLAG_FORW 1
# define MOVE_FLAG_BACK 2
# define MOVE_FLAG_LEFT 4
# define MOVE_FLAG_RIGHT 8
# define MOVE_FLAG_ROT_L 16
# define MOVE_FLAG_ROT_R 32


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
	char				**map;
	t_list				*walls;
	t_intpair			*map_size;
}						t_map;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_map				*map;
	t_img				*img;
}						t_mlx;

typedef struct			s_player
{
	float				angle;
	char				move_flags;
	t_floatpair			*pos;
	t_floatpair			*move;
	float				move_speed;
	float				rot_speed;
}						t_player;

typedef struct			s_settings
{
	float				fov;
	float				h_fov;
	float				dist;
	float				scale;
	float				proj_coeff;
	float				delta_angle;
	size_t					numrays;
	int				depth;
	t_intpair			*win_size;
	int				sq_size;
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
void	ft_print_map(t_map *map);
t_player	*ft_new_player(void);
t_settings *ft_default_settings(void);
int	draw_rectangle(t_game *game, t_intpair *pos, t_intpair *size, int color);
void	clear_window(t_game *game, int color);
void	draw_pixel(t_game *game, int x, int y, int color);
int	draw_line(t_game *game, t_intpair *start, t_intpair *stop, int color);
void	draw_map(t_game *game);

#endif
