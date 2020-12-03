#include <cub3d.h>

int		screenshot(t_game *game)
{
	draw_floor(game);
	draw_ceil(game);
	raycast_im(game);
	draw_sprites(game);
	save_bmp(game);
	clear_game(&game);
	return (0);
}
