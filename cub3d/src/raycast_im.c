#include <cub3d.h>

void	raycast_im(t_game *game)
{
	t_intpair	cur_tile;
	float		cur_angle;
	t_floatpair	start_pos;
	t_floatpair	depth;
	float		sin_a;
	float		cos_a;
	int		i;
	int		j;
	float		d;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		yv;
	int		xh;
	int		proj_heihgt;
	int		tex_ind;

	start_pos.x = game->player->pos->x;
	start_pos.y = game->player->pos->y;
	get_tile(&cur_tile, game->player->pos, game->settings->sq_size);
	cur_angle = game->player->angle - game->settings->h_fov;
	i = 0;
	depth.x = 0;
	depth.y = 0;
	while (i < game->settings->numrays )
	{
		sin_a = sin(cur_angle);
		cos_a = cos(cur_angle);
		// verticals
		x = (cos_a >= 0) ? cur_tile.x * game->settings->sq_size + game->settings->sq_size : cur_tile.x * game->settings->sq_size;
		dx = (cos_a >= 0) ? 1 : -1;
		j = 0;
		while (j < game->map->map_size->x)
		{
			depth.x = (x - start_pos.x) / cos_a;
			yv = start_pos.y + depth.x * sin_a;
			if (hit(game, (x + dx) / game->settings->sq_size, yv / game->settings->sq_size) == 1)
				break ;
			x += dx * game->settings->sq_size;
			j++;
		}
		//horizontals
		y = (sin_a >= 0) ? cur_tile.y * game->settings->sq_size + game->settings->sq_size : cur_tile.y * game->settings->sq_size;
		dy = (sin_a >= 0) ? 1 : -1;
		j = 0;
		while (j < FT_MAX(game->map->map_size->y, game->map->map_size->x))
		{
			depth.y = (y - start_pos.y) / sin_a;
			xh = start_pos.x + depth.y * cos_a;
			if (hit(game, xh / game->settings->sq_size, (y + dy) / game->settings->sq_size)== 1)
				break ;
			y += dy * game->settings->sq_size;
			j ++;
		}
		// projection
		tex_ind = get_tex_ind(game, &depth, x, y);
		d = get_dist(game, &depth, cur_angle);
		game->settings->z_buffer[i] = d;
		proj_heihgt = game->settings->proj_coeff / d * 2.5;
		game->map->textures[tex_ind]->offset = (depth.x < depth.y) ? yv : xh;
		game->map->textures[tex_ind]->offset %= game->settings->sq_size;
		draw_textured_rectangle(game, ft_new_intpair( i * game->settings->scale , game->settings->win_size->y / 2 - proj_heihgt / 2),ft_new_intpair(game->settings->scale + 1, proj_heihgt), game->map->textures[tex_ind]);
		i++;
		cur_angle += game->settings->delta_angle;
	}

}

