#include <cub3d.h>

static float		ft_map_zero(float x, float in_max, float out_max)
{
	return (x * out_max / in_max);
}

static t_intpair	*map_pos(t_game *game, int tile_size)
{
	int			height;
	int			width;
	t_intpair	*res;

	res = ft_new_intpair(0, 0);
	height = game->map->map_size->y * tile_size;
	width = game->map->map_size->x * tile_size;
	res->x = ft_map_zero(game->player->pos->x, game->map->map_size->x *
			game->settings->sq_size, width);
	res->y = ft_map_zero(game->player->pos->y, game->map->map_size->y *
			game->settings->sq_size, height);
	res->x -= tile_size / 4;
	res->y -= tile_size / 4;
	return (res);
}

static void			init_l(t_game *game, int *tile_size,
		t_intpair **pos, t_intpair **p)
{
	*tile_size = FT_MIN(game->settings->win_size->x,
			game->settings->win_size->y) / 50;
	*p = ft_new_intpair(0, 0);
	*pos = map_pos(game, *tile_size);
	(*p)->x = (*pos)->x + (*tile_size / 2) * cos(game->player->angle)
		+ *tile_size / 4;
	(*p)->y = (*pos)->y + (*tile_size / 2) * sin(game->player->angle)
		+ *tile_size / 4;
}

static void			draw_player(t_game *game, t_intpair *pos,
		int tile_size, t_intpair *p)
{
	draw_line(game, ft_new_intpair(pos->x + tile_size / 4,
				pos->y + tile_size / 4), p, 0xFFFFFF);
	draw_rectangle(game, map_pos(game, tile_size),
			ft_new_intpair(tile_size / 2, tile_size / 2), 0xFFFFFF);
}

void				draw_map(t_game *game)
{
	t_intpair	i;
	int			tile_size;
	int			color;
	t_intpair	*p;
	t_intpair	*pos;

	init_l(game, &tile_size, &pos, &p);
	i.x = 0;
	while (i.x < game->map->map_size->y)
	{
		i.y = 0;
		while (i.y < game->map->map_size->x)
		{
			color = ((game->map->map)[i.x][i.y] == '1') ? 0xDDDDDD : 0;
			color = ((game->map->map)[i.x][i.y] == '2') ? 0xFF07DD : color;
			draw_rectangle(game, ft_new_intpair(i.y * tile_size, i.x *
						tile_size),
					ft_new_intpair(tile_size - 1, tile_size - 1), color);
			i.y++;
		}
		i.x++;
	}
	draw_player(game, pos, tile_size, p);
	free(pos);
}
