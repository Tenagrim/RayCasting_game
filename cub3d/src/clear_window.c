#include <cub3d.h>

void	clear_window(t_game *game, int color)
{
	t_img	*img;
	int	x;
	int	y;
	int	width;

	img = game->mlx->img;
	width = game->settings->win_size->x;
	y = 0;
	while (y < game->settings->win_size->y)
	{
		x = 0;
		while (x < game->settings->win_size->x)
		{
			img->data[y * width + x] = color;
			x++;
		}
		y++;
	}
}
