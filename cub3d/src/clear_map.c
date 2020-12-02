#include <cub3d.h>

void		clear_img(t_game *game, t_img **img)
{
	if (*img)
	{
		mlx_destroy_image(game->mlx->mlx_ptr, (*img)->img_ptr);
		*img = NULL;
	}
}

static void	clear_arr(t_map *map)
{
	int	i;

	if (!(map->map))
		return ;
	i = 0;
	while (i < map->map_size->y)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
}

void		*clear_map(t_map **map)
{
	int	i;

	if (!(*map))
		return (NULL);
	clear_sprites(&((*map)->sprites));
	clear_arr(*map);
	if ((*map)->texture_paths)
	{
		i = 0;
		while (i++ < 5)
			if ((*map)->texture_paths[i - 1])
				free((*map)->texture_paths[i - 1]);
		free((*map)->texture_paths);
	}
	if ((*map)->map_size)
		free((*map)->map_size);
	*map = NULL;
	return (NULL);
}
