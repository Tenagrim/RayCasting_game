#include <cub3d.h>

void		clear_textures(t_game *game)
{
	int	i;

	if (!(game->map && game->map->textures))
		return ;
	i = 0;
	while (i < 5)
	{
		if (game->map->textures[i])
			clear_img(game, &(game->map->textures[i]));
		i++;
	}
	free(game->map->textures);
	game->map->textures = NULL;
}
