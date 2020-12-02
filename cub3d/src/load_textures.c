#include <cub3d.h>

static int	abort_l(t_game *game)
{
	clear_textures(game);
	return (0);
}

int		load_textures(t_game *game)
{
	int	i;
	t_img	*img;
	i = 0;
	while (i < 5)
	{
		img = load_texture(game, game->map->texture_paths[i]);
		if (!img)
			return (abort_l(game));
		game->map->textures[i] = img;
		i++;
	}
	return (1);
}
