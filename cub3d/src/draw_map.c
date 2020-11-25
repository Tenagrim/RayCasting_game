#include <cub3d.h>

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->map_size->y)
	{
		j = 0;
		while (j < game->map->map_size->x)
		{
			if ((game->map->map)[i][j] == '1')
				draw_rectangle(game, ft_new_intpair(j * game->settings->sq_size,i * game->settings->sq_size), ft_new_intpair(game->settings->sq_size - 1, game->settings->sq_size - 1), 0xDDDDDD);
			j++;
		}
		i++;
	}
}
