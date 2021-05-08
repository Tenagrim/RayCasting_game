#include <cub3d.h>

void	ft_print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_size->y)
	{
		ft_printf("%3d:  %s \n", i, map->map[i]);
		i++;
	}
}
