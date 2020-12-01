#include <cub3d.h>

static int ft_map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static t_intpair 	*map_pos(t_game *game, int tile_size)
{
	int		height;
	int		width;
	t_intpair	*res;

	res = ft_new_intpair(0,0);
	height = game->map->map_size->y * tile_size;
	width = game->map->map_size->x * tile_size;
	res->x = ft_map(game->player->pos->x, 0, game->map->map_size->x * game->settings->sq_size, 0, width);
	res->y = ft_map(game->player->pos->y, 0, game->map->map_size->y * game->settings->sq_size, 0, height);
	res->x -= tile_size / 4;
	res->y -= tile_size / 4;
	return (res);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;
	int	color;
	t_intpair	*p;
	t_intpair	*pos;
	int		d;

	i = 0;
	tile_size = 12;
	d = tile_size / 2;
	p = ft_new_intpair(0,0);
	pos = map_pos(game, tile_size);
	p->x = pos->x + d * cos(game->player->angle) + tile_size / 4;
	p->y = pos->y + d * sin(game->player->angle) + tile_size / 4;
	while (i < game->map->map_size->y)
	{
		j = 0;
		while (j < game->map->map_size->x)
		{
			color =  ((game->map->map)[i][j] == '1') ? 0xDDDDDD : 0;
			color =  ((game->map->map)[i][j] == '2') ? 0xFF07DD : color;
			draw_rectangle(game, ft_new_intpair(j * tile_size,i * tile_size), ft_new_intpair(tile_size - 1, tile_size - 1), color);
			j++;
		}
		i++;
	}
	//draw_rectangle(game, p, ft_new_intpair(tile_size / 6,tile_size / 6), 0xFFFFFF);
	draw_line(game, ft_new_intpair(pos->x+tile_size / 4, pos->y + tile_size / 4), p, 0xFFFFFF);
	draw_rectangle(game, map_pos(game, tile_size), ft_new_intpair(tile_size / 2,tile_size / 2), 0xFFFFFF);
	free(pos);
}
