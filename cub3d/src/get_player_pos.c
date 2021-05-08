#include <cub3d.h>

static int		get_pl_pos(t_game *game, char c, int i, int j)
{
	if (c && ft_strchr(MAP_DIRS_CHARS, c))
	{
		if (game->settings->parse_finds & PARSE_PL_POS_FOUND)
		{
			ft_printf("exit -1\n");
			return (-1);
		}
		game->settings->parse_finds |= PARSE_PL_POS_FOUND;
		if (c == 'N')
			game->player->angle = M_PI * 2 - M_PI / 2;
		else if (c == 'E')
			game->player->angle = 0.0;
		else if (c == 'S')
			game->player->angle = M_PI / 2;
		else if (c == 'W')
			game->player->angle = M_PI;
		game->player->pos->x = j * game->settings->sq_size +
			game->settings->sq_size / 2 + 1;
		game->player->pos->y = i * game->settings->sq_size +
			game->settings->sq_size / 2 + 1;
		game->player->angle += 0.000033;
	}
	return (0);
}

int				get_player_pos(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map->map_size->y)
	{
		j = 0;
		while (j < game->map->map_size->x)
		{
			c = game->map->map[i][j];
			if ((get_pl_pos(game, c, i, j)) == -1)
				return (0);
			j++;
		}
		i++;
	}
	return ((game->settings->parse_finds & PARSE_PL_POS_FOUND) ? 1 : 0);
}
