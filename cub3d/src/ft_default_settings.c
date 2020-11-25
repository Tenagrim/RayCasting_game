#include <cub3d.h>

t_settings *ft_default_settings(void)
{
	t_settings *res;

	res = (t_settings*)malloc(sizeof(t_settings));
	res->fov = M_PI / 3;
	res->h_fov = M_PI / 6;
	res->win_size = ft_new_intpair(800, 600);
	res->numrays = 80;
	res->delta_angle = res->fov / res->numrays;
	res->sq_size = 10;
	res->depth = 500;
	res->dist = res->numrays / (2 * tan(res->h_fov));
	res->scale = res->win_size->x / res->numrays;
	res->proj_coeff = res->dist * res->sq_size;
	return (res);
}
