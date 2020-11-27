#include <cub3d.h>

t_settings *ft_default_settings(void)
{
	t_settings *res;

	res = (t_settings*)malloc(sizeof(t_settings));
	res->fov = M_PI / 3;
	res->h_fov = M_PI / 6;
	res->win_size = ft_new_intpair(800, 600);
	res->numrays = 300;
	res->delta_angle = res->fov / res->numrays;
	res->sq_size = 64;
	res->depth = 500;
	res->dist = res->numrays / (2 * tan(res->h_fov));
	res->scale = (float)res->win_size->x / (float)res->numrays;
	res->texture_size = ft_new_intpair(64, 64);
	res->texture_scale = res->texture_size->x / (float)res->sq_size;
	res->proj_coeff = res->dist * res->sq_size;
	res->floor_color = 0;
	res->ceil_color = 0;
	res->settings = SETT_SHADOWS_ON | SETT_MAP_ON;
	ft_printf("scale: %f\n", res->scale);
	res->parse_finds = 0;
	return (res);
}
