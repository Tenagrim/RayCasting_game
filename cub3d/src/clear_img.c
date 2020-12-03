#include <cub3d.h>

void		clear_img(t_game *game, t_img **img)
{
	if (*img)
	{
		mlx_destroy_image(game->mlx->mlx_ptr, (*img)->img_ptr);
		free(*img);
		*img = NULL;
	}
}
