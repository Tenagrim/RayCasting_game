#include <cub3d.h>

void	clear_mlx(t_game *game)
{
	if (!(game->mlx))
		return ;
	if (game->mlx->img)
		clear_img(game, &(game->mlx->img));
	if (game->mlx->mlx_ptr && game->mlx->win)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win);
	free(game->mlx);
	game->mlx = NULL;
}
