#include <cub3d.h>

void	clear_game(t_game **game)
{
	if (*game)
	{
		clear_textures(*game);
		clear_map(&((*game)->map));
		clear_settings(*game);
		clear_player(*game);
		clear_mlx(*game);
		free(*game);
		*game = NULL;
	}
}
