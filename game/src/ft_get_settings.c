#include <cub3d.h>

void	ft_get_settings(t_game *game)
{
	t_settings *res;

	res = game->settings;
	if (res->win_size->x < res->numrays)
	{
		res->numrays = res->win_size->x;
		free(res->z_buffer);
		res->z_buffer = (float*)malloc(sizeof(float) * res->numrays);
		res->delta_angle = res->fov / res->numrays;
		res->dist = res->numrays / (2 * tan(res->h_fov));
		res->proj_coeff = res->sq_size;
	}
	res->scale = (float)res->win_size->x / (float)res->numrays;
	res->proj_mult = res->scale / 2.5;
}

/*
**	res->proj_coeff = res->dist * res->sq_size;
*/
