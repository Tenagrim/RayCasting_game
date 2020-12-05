/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:47:57 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 20:48:40 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>
# include <keys_mac.h>
# define _USE_MATH_DEFINES
# define FT_MIN(a, b) (((a) < (b) ? (a) : (b)))
# define FT_MAX(a, b) (((a) < (b) ? (b) : (a)))
# define WIN_NAME "Cub3D"
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17
# define MOVE_FLAG_FORW	1<<0
# define MOVE_FLAG_BACK	1<<1
# define MOVE_FLAG_LEFT	1<<2
# define MOVE_FLAG_RIGHT	1<<3
# define MOVE_FLAG_ROT_L	1<<4
# define MOVE_FLAG_ROT_R	1<<5
# define SETT_SHADOWS_ON	1<<0
# define SETT_MAP_ON	1<<1
# define SETT_COLL_ON	1<<2
# define SETT_COLL_ON	1<<2
# define PARSE_RES_FOUND	1<<0
# define PARSE_N_TEX_FOUND	1<<1
# define PARSE_W_TEX_FOUND	1<<2
# define PARSE_S_TEX_FOUND	1<<3
# define PARSE_E_TEX_FOUND	1<<4
# define PARSE_SPRITE_TEX_FOUND	1<<5
# define PARSE_C_COLOR_FOUND	1<<6
# define PARSE_F_COLOR_FOUND	1<<7
# define PARSE_PL_POS_FOUND	1<<8
# define MAP_CHARS "NWSE012 "
# define MAP_DIRS_CHARS "NWSE"

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
	int					width;
	int					height;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					offset;
	int					shadow;
}						t_img;

typedef struct			s_sprite
{
	struct s_sprite		*next;
	struct s_sprite		*sorted;
	t_floatpair			*pos;
	float				dist;
}						t_sprite;

typedef struct			s_map
{
	char				**map;
	t_sprite			*sprites;
	t_img				**textures;
	char				**texture_paths;
	t_intpair			*map_size;
}						t_map;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_img				*img;
}						t_mlx;

typedef struct			s_player
{
	float				angle;
	char				move_flags;
	t_floatpair			*pos;
	float				move_speed;
	float				run_speed;
	float				walk_speed;
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
	int					numrays;
	int					depth;
	t_intpair			*win_size;
	int					sq_size;
	t_intpair			*texture_size;
	float				texture_scale;
	int					floor_color;
	int					ceil_color;
	char				settings;
	int					parse_finds;
	float				shadow_mult;
	float				*z_buffer;
	float				body;
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
t_floatpair				*ft_new_floatpair(float	x, float y);
t_map					*ft_get_map_from_file(t_game *game, char *filename);
int						key_press(int keycode, t_game *game);
int						key_release(int keycode, t_game *game);
int						exit_game(t_game *game, int code);
int						exit_hook(t_game *game);
int						ft_main_loop(t_game *game);
void					update_window(t_game *game);
void					ft_print_map(t_map *map);
t_player				*ft_new_player(void);
t_settings				*ft_default_settings(void);
int						draw_rectangle(t_game *game, t_intpair *pos,
		t_intpair *size, int color);
void					clear_window(t_game *game, int color);
void					draw_pixel(t_game *game, int x, int y, int color);
int						draw_line(t_game *game, t_intpair *start,
		t_intpair *stop, int color);
void					draw_map(t_game *game);
t_img					*load_texture(t_game *game, char *filename);
int						draw_textured_rectangle(t_game *game, t_intpair *pos,
		t_intpair *size, t_img *texture);
t_sprite				*ft_sprtnew(t_floatpair *pos);
void					ft_sprtadd_front(t_sprite **list, t_sprite *add);
void					ft_copy_intpair(t_intpair *dest, t_intpair *src);
t_sprite				*ft_sprtadd_sorted(t_sprite **sorted, t_sprite *sprite);
t_sprite				*ft_sort_sprites(t_game *game, t_sprite *sprites);
void					ft_get_settings(t_game *game);
void					draw_floor(t_game *game);
void					draw_ceil(t_game *game);
void					raycast_im(t_game *game);
float					get_dist(t_game *game, t_floatpair *depth,
		float cur_angle);
int						get_tex_ind(t_game *game, t_floatpair *depth,
		int x, int y);
void					get_tile(t_intpair *res, t_floatpair *pos, int sq_size);
int						hit(t_game *game, int x, int y);
void					rotate(t_game *game, char dir);
void					movement(t_game *game);
void					draw_sprites(t_game *game);
int						validate_map(t_map *map);
int						error_map_line(int i, char *line, char dir);
int						get_player_pos(t_game *game);
int						parse_map(t_game *game, t_list *file);
int						load_textures(t_game *game);
int						parse_c_color(t_game *game, t_list *file);
int						parse_f_color(t_game *game, t_list *file);
char					*find_line(t_list *file, char *key);
int						parse_tex_paths(t_game *game, t_list *file);
int						parse_res(t_game *game, t_list *file);
int						ft_clear_split(char ***splitted);
int						ft_count_splitted(char **splitted);
t_game					*init_game(char **av);
t_map					*init_map(void);
t_mlx					*init_mlx(void);
void					*clear_map(t_map **map);
void					clear_file(t_list *file);
void					clear_sprites(t_sprite **sprites);
void					clear_textures(t_game *game);
void					clear_img(t_game *game, t_img **img);
void					clear_player(t_game *game);
void					clear_settings(t_game *game);
void					clear_mlx(t_game *game);
void					clear_game(t_game **game);
int						screenshot(t_game *game);
int						save_bmp(t_game *game);
int						check_filename(char *name);

#endif
