#include <cub3d.h>

static void	draw_sprite(t_game *game, t_sprite *sprite)
{
	int		proj_heihgt;
	t_floatpair	d;
	float		thetha;
	float		gamma;
	int		delta_rays;
	int		curr_ray;
	t_intpair	pos;
	int		stop_x;
	int		start_x;
	int		start_ray;
	int		stop_ray;
	int		numrays;
	float		dist;

	d.x = sprite->pos->x - game->player->pos->x;
	d.y = sprite->pos->y - game->player->pos->y;
	thetha = atan2(d.y, d.x);
	gamma = thetha - game->player->angle;

	if ((d.x > 0 && (M_PI <= game->player->angle && game->player->angle <= 2 * M_PI)) || (d.x < 0 && d.y < 0))
		gamma += 2 * M_PI;
	delta_rays = (int)(gamma / (float)game->settings->delta_angle);
	curr_ray = game->settings->numrays / 2 - 1 + delta_rays;
	dist = sprite->dist ;
	if (dist < game->settings->sq_size / 4.)
		return ;
	proj_heihgt = game->settings->proj_coeff / dist * 2.5;
	numrays = proj_heihgt / game->settings->scale + 1;
	start_ray = curr_ray -  numrays / 2;
	stop_ray = curr_ray + numrays / 2;
	pos.x = curr_ray * game->settings->scale - proj_heihgt / 2;
	pos.y = game->settings->win_size->y / 2 - proj_heihgt / 2;
	stop_x = pos.x + proj_heihgt;
	start_x = pos.x;
	if ((start_ray < 0 && stop_ray < 0) || (start_ray >= game->settings->numrays &&  stop_ray >= game->settings->numrays))
		return ;
	while (pos.x <= stop_x - game->settings->scale && pos.x < game->settings->win_size->x)
	{
		game->map->textures[4]->offset = (pos.x - start_x)  * game->settings->texture_size->x / proj_heihgt; 
		if (pos.x >= 0  && sprite->dist < game->settings->z_buffer[(int)(pos.x / game->settings->scale)] && pos.x >= 0)
			draw_textured_rectangle(game, ft_new_intpair(pos.x, pos.y), ft_new_intpair(game->settings->scale, proj_heihgt), game->map->textures[4]);
		pos.x += game->settings->scale;
	}
}

void	draw_sprites(t_game *game)
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
