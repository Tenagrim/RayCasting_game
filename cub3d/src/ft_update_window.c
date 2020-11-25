#include <cub3d.h>

void update_window(t_game *game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
}
