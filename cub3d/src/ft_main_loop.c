#include <cub3d.h>

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
