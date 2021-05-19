#include <cub3d.h>

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
	free(map->map);
	map->map = NULL;
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
	free(*map);
	*map = NULL;
	return (NULL);
}
