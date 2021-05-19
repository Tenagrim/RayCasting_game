#include <draw_sprite_args.h>

static int		calc_args(t_game *game, t_sprite *sprite, t_draw_sprite_args *a)
{
	a->thetha = atan2(a->d.y, a->d.x);
	a->gamma = a->thetha - game->player->angle;
	if ((a->d.x > 0 && (M_PI <= game->player->angle &&
			game->player->angle <= 2 * M_PI)) ||
			(a->d.x < 0 && a->d.y < 0))
		a->gamma += 2 * M_PI;
	a->delta_rays = (int)(a->gamma / (float)game->settings->delta_angle);
	a->curr_ray = game->settings->numrays / 2 - 1 + a->delta_rays;
	a->dist = sprite->dist;
	if (a->dist < game->settings->sq_size / 4.)
		return (0);
	a->proj_heihgt = game->settings->proj_coeff / a->dist *
		game->settings->proj_mult;
	a->numrays = a->proj_heihgt / game->settings->scale + 1;
	a->start_ray = a->curr_ray - a->numrays / 2;
	a->stop_ray = a->curr_ray + a->numrays / 2;
	a->pos.x = a->curr_ray * game->settings->scale - a->proj_heihgt / 2 - 1;
	a->pos.y = game->settings->win_size->y / 2 - a->proj_heihgt / 2;
	a->stop_x = a->pos.x + a->proj_heihgt;
	a->start_x = a->pos.x;
	if ((a->start_ray < 0 && a->stop_ray < 0) ||
			(a->start_ray >= game->settings->numrays &&
			a->stop_ray >= game->settings->numrays))
		return (0);
	return (1);
}

static void		draw_sprite(t_game *game, t_sprite *sprite)
{
	t_draw_sprite_args	a;

	a.d.x = sprite->pos->x - game->player->pos->x;
	a.d.y = sprite->pos->y - game->player->pos->y;
	if (!(calc_args(game, sprite, &a)))
		return ;
	while (a.pos.x <= a.stop_x - game->settings->scale &&
			a.pos.x < game->settings->win_size->x)
	{
		game->map->textures[4]->offset = (a.pos.x - a.start_x) *
			game->settings->texture_size->x / a.proj_heihgt;
		if (a.pos.x >= 0 && sprite->dist <
				game->settings->z_buffer[(int)(a.pos.x /
					game->settings->scale)] && a.pos.x >= 0)
			draw_textured_rectangle(game,
					ft_new_intpair(a.pos.x, a.pos.y),
					ft_new_intpair(game->settings->scale,
						a.proj_heihgt),
					game->map->textures[4]);
		a.pos.x += game->settings->scale;
	}
}

void			draw_sprites(t_game *game)
{
	t_sprite	*sorted;

	sorted = ft_sort_sprites(game, game->map->sprites);
	while (sorted)
	{
		if (sorted->dist > game->settings->sq_size / 6)
			draw_sprite(game, sorted);
		sorted = sorted->sorted;
	}
}
