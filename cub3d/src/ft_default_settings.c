#include <cub3d.h>

t_settings *ft_default_settings(void)
{
	t_settings *res;

	res = (t_settings*)malloc(sizeof(t_settings));
	res->fov = M_PI / 3;
	res->h_fov = M_PI / 6;
	res->win_size = ft_new_intpair(800, 600);
	res->numrays = 300;
	res->z_buffer = (float*)malloc(sizeof(float) * res->numrays);
	res->delta_angle = res->fov / res->numrays;
	res->sq_size = 64;
	//res->depth = 600;
	res->dist = res->numrays / (2 * tan(res->h_fov));
	res->scale = (float)res->win_size->x / (float)res->numrays;
	res->texture_size = ft_new_intpair(64, 64);
	res->texture_scale = res->texture_size->x / (float)res->sq_size;
	res->proj_coeff = res->dist * res->sq_size;
	ft_printf ("proj_coeff: %f\n", res->proj_coeff);
	ft_printf ("dist: %f\n", res->dist);
	res->floor_color = 0xA1002C;
	//res->floor_color = 0xFFFFFF;
	res->ceil_color = 0x00002C;
	//res->ceil_color = 0xFFFFFF;
	res->settings = 0;//SETT_SHADOWS_ON | SETT_MAP_ON;
	ft_printf("scale: %f\n", res->scale);
	res->parse_finds = 0;
	res->shadow_mult = 0.000027;
	return (res);
}
