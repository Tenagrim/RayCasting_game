#include <cub3d.h>

/*
 ** dist = sprite->dist * cos(game->settings->h_fov - curr_ray * game->settings->delta_angle); // ????  fisheye
 */

int		ft_main_loop(t_game *game)
{
	draw_floor(game);
	draw_ceil(game);
	movement(game);
	raycast_im(game);
	draw_sprites(game);
	if (game->settings->settings & SETT_MAP_ON)
		draw_map(game);
	update_window(game);
	return (0);
}
