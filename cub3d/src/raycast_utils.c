#include <cub3d.h>

int	hit(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map->map_size->x || y >= game->map->map_size->y)
		return (0);
	if (game->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}


void	get_tile(t_intpair *res, t_floatpair *pos, int sq_size)
{
	res->x = pos->x / sq_size;
	res->y = pos->y / sq_size;
}

int	get_tex_ind(t_game *game, t_floatpair *depth, int x, int y)
{
	if (depth->x < depth->y)
	{
		if (game->player->pos->x < x)
			return (1);
		else
			return (3);
	}
	else
	{
		if (game->player->pos->y < y)
			return (0);
		else
			return (2);
	}
}

float	get_dist(t_game *game, t_floatpair *depth, float cur_angle)
{
	float	d;

	d = (depth->x < depth->y) ? depth->x : depth->y;
	d *= cos(game->player->angle - cur_angle);
	d = FT_MAX(d, 0.00001);
	return (d);
}

