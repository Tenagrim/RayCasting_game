#include <cub3d.h>

static int	hit(t_game *game, int x, int y)
{
	t_list		*p;
	t_intpair	*pos;

	p = game->map->walls;
	//ft_printf("%d    %d\n", x, y);
	while (p)
	{
		pos = (t_intpair*)(p->content);
		if (pos->x == x && pos->y == y)
		{
			//ft_printf("HIT\n");
			return (1);
		}
		p = p->next;
	}
	return (0);
}

static void	rotate(t_game *game, char dir)
{
	if (dir)
		game->player->angle -= game->player->rot_speed;
	else
		game->player->angle += game->player->rot_speed;
/*
	if (game->player->angle > 1.0)
		game->player->angle = game->player->angle - 1;
	if (game->player->angle < -1.0)
		game->player->angle = game->player->angle + 1;
*/
}

static void	get_tile(t_intpair *res, t_floatpair *pos, int sq_size)
{	
	res->x = pos->x / sq_size;
	res->y = pos->y / sq_size;
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
	int		dx;
	int		y;
	int		dy;
	int		proj_heihgt;
	int		c;

	start_pos.x = game->player->pos->x;
	start_pos.y = game->player->pos->y;
	get_tile(&cur_tile, game->player->pos, game->settings->sq_size);
	cur_angle = game->player->angle - game->settings->h_fov;
	//ft_printf("%d   %d\n", cur_tile.x, cur_tile.y);
	i = 0;
	depth.x = 0;
	depth.y = 0;
	while (i < game->settings->numrays)
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
			y = start_pos.y + depth.x * sin_a;
			if (hit(game, (x + dx) / game->settings->sq_size, y / game->settings->sq_size))
				break ;
			x += dx * game->settings->sq_size;
			j++;
		}
		//horizontals
		y = (sin_a >= 0) ? cur_tile.y * game->settings->sq_size + game->settings->sq_size : cur_tile.y * game->settings->sq_size;
		dy = (sin_a >= 0) ? 1 : -1;
		j = 0;
		while (j < game->map->map_size->y)
		{
			depth.y = (y - start_pos.y) / sin_a;
			x = start_pos.x + depth.y * cos_a;
			if (hit(game, x / game->settings->sq_size, (y + dy) / game->settings->sq_size))
				break ;
			y += dy * game->settings->sq_size;
			j ++;
		}
		d = (depth.x < depth.y) ? depth.x : depth.y;
		d *= cos(game->player->angle - cur_angle);
		proj_heihgt = game->settings->proj_coeff / d * 2;
		c = 255 / (1 + d * d * 0.001);
		//draw_line(game, ft_new_intpair(start_pos.x, start_pos.y), ft_new_intpair(x, y), 0xAAAAAA);
		//ft_printf("%d   %d\n",x, y);
		draw_rectangle(game, ft_new_intpair( i * game->settings->scale, game->settings->win_size->y / 2 - proj_heihgt / 2),ft_new_intpair( game->settings->scale, proj_heihgt), 0 | c<<16 | c<<8 | c);
		i++;
		cur_angle += game->settings->delta_angle;
	}

}

static void	raycast(t_game *game)
{
	float		cur_angle;
	t_floatpair	start_pos;
	size_t		i;
	float		j;
	float		sin_a;
	float		cos_a;
	int		x;
	int		y;
	int		proj_heihgt;
	int		c;

	start_pos.x = game->player->pos->x;
	start_pos.y = game->player->pos->y;
	cur_angle = game->player->angle - game->settings->h_fov;
	i = 0;
	while (i < game->settings->numrays)
	{
		sin_a = sin(cur_angle);
		cos_a = cos(cur_angle);
		j = 0;
		while (j < game->settings->depth)
		{
			x = start_pos.x + j * cos_a;
			y = start_pos.y + j * sin_a;
			//draw_line(game, ft_new_intpair(start_pos.x, start_pos.y), ft_new_intpair(x, y), 0xAAAAAA);
			if (hit(game, x / game->settings->sq_size, y / game->settings->sq_size))
			{
				j *= cos(game->player->angle - cur_angle);
				proj_heihgt = game->settings->proj_coeff / j * 2;
				c = 255 / (1 + j * j * 0.001);
				draw_rectangle(game, ft_new_intpair( i * game->settings->scale, game->settings->win_size->y / 2 - proj_heihgt / 2),ft_new_intpair( game->settings->scale, proj_heihgt), 0 | c<<16 | c<<8 | c);
				break ;
			}
			j += 1;
		}
		i++;
		cur_angle += game->settings->delta_angle;
	}
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

int		ft_main_loop(t_game *game)
{


	clear_window(game, 0);
	//draw_line(game, ft_new_intpair(0,0), ft_new_intpair(100,100), 0xFFFFFF);
	movement(game);
	//raycast(game);
	raycast_im(game);
	draw_map(game);
	update_window(game);
	//ft_printf(">>%p\n", game->mlx->mlx_ptr);
	//ft_printf("%d \n", i++);
	return (0);
}
