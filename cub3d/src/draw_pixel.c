#include <cub3d.h>

void	draw_pixel(t_game *game, int x, int y, int color)
{
	t_img	*img;

	img = game->mlx->img;
	img->data[y * game->settings->win_size->x + x] = color;
}
