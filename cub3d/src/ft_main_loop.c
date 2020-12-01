#include <cub3d.h>

static int	hit(t_game *game, int x, int y)
{
	/*
	t_list		*p;
	t_intpair	*pos;

	p = game->map->walls;
	while (p)
	{
		pos = (t_intpair*)(p->content);
		if (pos->x == x && pos->y == y)
			return (1);
		p = p->next;
	}
	*/
	if (x < 0 || y < 0 || x >= game->map->map_size->x || y >= game->map->map_size->y)
		return (0);
	if (game->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}


static void	get_tile(t_intpair *res, t_floatpair *pos, int sq_size)
{
	res->x = pos->x / sq_size;
	res->y = pos->y / sq_size;
}

static int	get_tex_ind(t_game *game, t_floatpair *depth, int x, int y)
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

static float	get_dist(t_game *game, t_floatpair *depth, float cur_angle)
{
	float	d;

	d = (depth->x < depth->y) ? depth->x : depth->y;
	d *= cos(game->player->angle - cur_angle);
	d = FT_MAX(d, 0.00001);
	return (d);
}

static void	raycast_im(t_game *game)
{
	t_intpair	cur_tile;
	float		cur_angle;
	t_floatpair	start_pos;
	t_floatpair	depth;
	float		sin_a;
	float		cos_a;
	size_t		i;
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
		game->map->textures[tex_ind]->shadow = 255 - (255 / (1 + d * d * game->settings->shadow_mult));
		draw_textured_rectangle(game, ft_new_intpair( (i * game->settings->scale)  , game->settings->win_size->y / 2 - proj_heihgt / 2),ft_new_intpair((game->settings->scale + 1) , proj_heihgt), game->map->textures[tex_ind]);
		i++;
		cur_angle += game->settings->delta_angle;
	}

}

/*
static int	ft_pow(int a, int b)
{
	int res = 1;

	while (b--)
		res *= a;
	return (res);
}
*/

static void	rotate(t_game *game, char dir)
{
	float d_pi;

	d_pi = (float)(M_PI * 2);
	if (dir)
		game->player->angle -= game->player->rot_speed;
	else
		game->player->angle += game->player->rot_speed;
	if (game->player->angle >= d_pi)
		game->player->angle -= d_pi;
	if (game->player->angle <= 0)
		game->player->angle = d_pi;
}

static void	movement(t_game *game)
{
	float	a;

	a = game->player->angle;
	if (game->player->move_flags & MOVE_FLAG_FORW)
	{
		game->player->pos->x += game->player->move_speed * cos(a);
		game->player->pos->y += game->player->move_speed * sin(a);
	}
	if (game->player->move_flags & MOVE_FLAG_BACK)
	{
		game->player->pos->x -= game->player->move_speed * cos(a);
		game->player->pos->y -= game->player->move_speed * sin(a);
	}
	if (game->player->move_flags & MOVE_FLAG_LEFT)
	{
		game->player->pos->x += game->player->move_speed * sin(a);
		game->player->pos->y -= game->player->move_speed * cos(a);
	}
	if (game->player->move_flags & MOVE_FLAG_RIGHT)
	{
		game->player->pos->x -= game->player->move_speed * sin(a);
		game->player->pos->y += game->player->move_speed * cos(a);
	}
	if (game->player->move_flags & MOVE_FLAG_ROT_L)
		rotate(game, 1);
	if (game->player->move_flags & MOVE_FLAG_ROT_R)
		rotate(game, 0);
}

static int	get_shadow(int c, int dist, int max)
{
	int shadow;
	shadow = ((dist) * (1 + 0.027 )  * 255 / (max));
	c = FT_MAX(0, ((((c & 0xFF0000) >> 16) - shadow) << 16)) |
		FT_MAX(0, ((((c & 0x00FF00) >> 8) - shadow) << 8)) |
		FT_MAX(0, ((c & 0x0000FF) - shadow));
	return (c);
}

static void	draw_floor(t_game *game)
{
	t_img		*img;
	int		c;
	t_intpair	coords;

	img = game->mlx->img;
	coords.y = game->settings->win_size->y / 2;
	while (coords.y < game->settings->win_size->y)
	{
		coords.x = 0;
		c = game->settings->floor_color;
		if (game->settings->settings & SETT_SHADOWS_ON)
			c = get_shadow(c, game->settings->win_size->y - coords.y, game->settings->win_size->y / 2);
		while (coords.x < game->settings->win_size->x)
		{
			img->data[coords.y * game->settings->win_size->x + coords.x] = c;
			coords.x++;
		}
		coords.y++;
	}
}

static void	draw_ceil(t_game *game)
{
	t_img		*img;
	int		c;
	t_intpair	coords;

	img = game->mlx->img;
	coords.y = 0;
	while (coords.y < game->settings->win_size->y / 2)
	{
		coords.x = 0;
		c = game->settings->ceil_color;
		if (game->settings->settings & SETT_SHADOWS_ON)
			c = get_shadow(c, coords.y,  game->settings->win_size->y / 2);
		while (coords.x < game->settings->win_size->x)
		{
			img->data[coords.y * game->settings->win_size->x + coords.x] = c;
			coords.x++;
		}
		coords.y++;
	}
}

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
	//ft_printf("gamma: %f\n", gamma);
	curr_ray = game->settings->numrays / 2 - 1 + delta_rays;
	//ft_printf("angle: %f\n", game->player->angle);
	//ft_printf("start: %d   stop %d\n", start_ray, stop_ray);
	dist = sprite->dist * cos(game->settings->h_fov - curr_ray * game->settings->delta_angle); // ????  fisheye
	dist = FT_MAX(dist, 0.0000000001);
	//ft_printf("dist: %f\n", dist);
	if (dist < game->settings->sq_size / 6.)
		return ;
	proj_heihgt = game->settings->proj_coeff / dist * 2.5;
	//proj_heihgt = game->settings->proj_coeff / sprite->dist  * 2.5;
	numrays = proj_heihgt / game->settings->scale + 1;
	start_ray = curr_ray -  numrays / 2;
	stop_ray = curr_ray + numrays / 2;
	//ft_printf("start: %d  stop: %d\n", start_ray, stop_ray);
	pos.x = curr_ray * game->settings->scale - proj_heihgt / 2;
	pos.y = game->settings->win_size->y / 2 - proj_heihgt / 2;
	stop_x = pos.x + proj_heihgt;
	start_x = pos.x;
	if ((start_ray < 0 && stop_ray < 0) || (start_ray >= game->settings->numrays &&  stop_ray >= game->settings->numrays))
		return ;
	//ft_printf("pos.x: %d\n", curr_ray);
	while (pos.x <= stop_x - game->settings->scale && pos.x < game->settings->win_size->x)
	{
		//ft_printf(">>>%x\n", game->map->textures[4]->data[0]);
		game->map->textures[4]->offset = (pos.x - start_x)  * game->settings->texture_size->x / proj_heihgt; 
		//ft_printf("delta_rays: %d  curr_ray: %d \n", delta_rays, curr_ray);
		//ft_printf("wall dist: %f  sp dist %f\n", game->settings->z_buffer[curr_ray], sprite->dist);
		if (pos.x >= 0  && sprite->dist < game->settings->z_buffer[(int)(pos.x / game->settings->scale)] && pos.x >= 0)
		{
		//printf("111\n");
			//draw_rectangle(game, ft_new_intpair(pos.x, pos.y), ft_new_intpair(game->settings->scale, proj_heihgt), 0);
			draw_textured_rectangle(game, ft_new_intpair(pos.x, pos.y), ft_new_intpair(game->settings->scale, proj_heihgt), game->map->textures[4]);
		}
		pos.x += game->settings->scale;
	}
}

static void	draw_sprites(t_game *game)
{
	t_sprite	*sorted;

	sorted = ft_sort_sprites(game, game->map->sprites);
	while (sorted)
	{
		if (sorted->dist > game->settings->sq_size / 6)
			draw_sprite(game, sorted);
		//ft_printf("drawing sprite. dist: %f\n", sorted->dist);
		sorted = sorted->sorted;
	}
}

int		ft_main_loop(t_game *game)
{
	draw_floor(game);
	draw_ceil(game);
	movement(game);
	raycast_im(game);
	draw_sprites(game);
	if (game->settings->settings & SETT_MAP_ON)
		draw_map(game);
	update_window(game);
	//mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, game->map->textures[0]->img_ptr, 0, 0);
	//mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, game->map->textures[1]->img_ptr, 64, 0);
	//mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, game->map->textures[2]->img_ptr, 64 * 2, 0);
	//mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, game->map->textures[3]->img_ptr, 64 * 3, 0);
	//mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, game->map->textures[4]->img_ptr, 64 * 4, 0);
	//ft_printf(">>%p\n", game->mlx->mlx_ptr);
	//ft_printf("%d \n", i++);
	return (0);
}
