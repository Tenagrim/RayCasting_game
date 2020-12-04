#ifndef RAYCAST_ARGS_H
# define RAYCAST_ARGS_H
# include <cub3d.h>

typedef struct		s_raycast_args
{
	t_intpair	cur_tile;
	float		cur_angle;
	t_floatpair	start_pos;
	t_floatpair	depth;
	float		sin_a;
	float		cos_a;
	int		i;
	int		j;
	float		d;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		yv;
	int		xh;
	int		proj_heihgt;
	int		tex_ind;
}			t_raycast_args;
#endif
