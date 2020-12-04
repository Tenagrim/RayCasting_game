#include <raycast_args.h>

static void	init_args(t_game *game, t_raycast_args *a)
{
	a->start_pos.x = game->player->pos->x;
	a->start_pos.y = game->player->pos->y;
	get_tile(&(a->cur_tile), game->player->pos, game->settings->sq_size);
	a->cur_angle = game->player->angle - game->settings->h_fov;
	a->i = 0;
	a->depth.x = 0;
	a->depth.y = 0;
}

static void	verticals(t_game *game, t_raycast_args *a)
{
	int	max;

	max = FT_MAX(game->map->map_size->y, game->map->map_size->x);
	a->x = (a->cos_a >= 0) ? a->cur_tile.x * game->settings->sq_size +
		game->settings->sq_size : a->cur_tile.x *
		game->settings->sq_size;
	a->dx = (a->cos_a >= 0) ? 1 : -1;
	a->j = 0;
	while (a->j < max)
	{
		a->depth.x = (a->x - a->start_pos.x) / a->cos_a;
		a->yv = a->start_pos.y + a->depth.x * a->sin_a;
		if (hit(game, (a->x + a->dx) / game->settings->sq_size, a->yv /
					game->settings->sq_size) == 1)
			break ;
		a->x += a->dx * game->settings->sq_size;
		a->j++;
	}

}

static void	horizontals(t_game *game, t_raycast_args *a)
{
	int	max;

	max = FT_MAX(game->map->map_size->y, game->map->map_size->x);
	a->y = (a->sin_a >= 0) ? a->cur_tile.y *
		game->settings->sq_size + game->settings->sq_size :
		a->cur_tile.y * game->settings->sq_size;
	a->dy = (a->sin_a >= 0) ? 1 : -1;
	a->j = 0;
	while (a->j < max)
	{
		a->depth.y = (a->y - a->start_pos.y) / a->sin_a;
		a->xh = a->start_pos.x + a->depth.y * a->cos_a;
		if (hit(game, a->xh / game->settings->sq_size, (a->y + a->dy) /
					game->settings->sq_size)== 1)
			break ;
		a->y += a->dy * game->settings->sq_size;
		a->j++;
	}
}

static void	projection(t_game *game, t_raycast_args *a)
{
	a->tex_ind = get_tex_ind(game, &(a->depth), a->x, a->y);
	a->d = get_dist(game, &(a->depth), a->cur_angle);
	game->settings->z_buffer[a->i] = a->d;
	a->proj_heihgt = game->settings->proj_coeff / a->d * 2.5;
	game->map->textures[a->tex_ind]->offset = (a->depth.x < a->depth.y) ?
		a->yv : a->xh;
	game->map->textures[a->tex_ind]->offset %= game->settings->sq_size;
	draw_textured_rectangle(game, ft_new_intpair(a->i *
				game->settings->scale ,
				game->settings->win_size->y / 2 -
				a->proj_heihgt / 2),
			ft_new_intpair(game->settings->scale + 1,
				a->proj_heihgt),
			game->map->textures[a->tex_ind]);
	a->i++;
	a->cur_angle += game->settings->delta_angle;
}

void	raycast_im(t_game *game)
{
	t_raycast_args	a;

	init_args(game, &a);
	while (a.i < game->settings->numrays )
	{
		a.sin_a = sin(a.cur_angle);
		a.cos_a = cos(a.cur_angle);
		verticals(game, &a);
		horizontals(game, &a);
		projection(game, &a);
	}
}

