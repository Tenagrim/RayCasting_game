#ifndef DRAW_SPRITE_ARGS_H
# define DRAW_SPRITE_ARGS_H
# include <cub3d.h>

typedef struct		s_draw_sprite_args
{
	int				proj_heihgt;
	t_floatpair		d;
	float			thetha;
	float			gamma;
	int				delta_rays;
	int				curr_ray;
	t_intpair		pos;
	int				stop_x;
	int				start_x;
	int				start_ray;
	int				stop_ray;
	int				numrays;
	float			dist;
}					t_draw_sprite_args;
#endif
