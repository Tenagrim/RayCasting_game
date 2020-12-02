#include <cub3d.h>

int		load_textures(t_game *game)
{
	int	i;
	t_img	*img;
	i = 0;
	while (i < 5)
	{
		img = load_texture(game, game->map->texture_paths[i]);
		if (!img)
			return (0);
		game->map->textures[i] = img;
		i++;
	}
	return (1);
}
