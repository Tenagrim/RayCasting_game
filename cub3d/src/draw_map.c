#include <cub3d.h>

static float ft_map_zero(float x, float in_max, float out_max)
{
  return x * out_max  / in_max;
}

static t_intpair 	*map_pos(t_game *game, int tile_size)
{
	int		height;
	int		width;
	t_intpair	*res;

	res = ft_new_intpair(0,0);
	height = game->map->map_size->y * tile_size;
	width = game->map->map_size->x * tile_size;
	res->x = ft_map_zero(game->player->pos->x, game->map->map_size->x * game->settings->sq_size, width);
	res->y = ft_map_zero(game->player->pos->y, game->map->map_size->y * game->settings->sq_size, height);
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
	tile_size = FT_MIN(game->settings->win_size->x, game->settings->win_size->y) / 50;
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
