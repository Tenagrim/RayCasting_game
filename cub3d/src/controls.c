/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:41 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:39:26 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		rotate(t_game *game, char dir)
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

static void	coll_x(t_game *game, float dx)
{
	float	pos;
	float	body;

	if (game->settings->settings & SETT_COLL_ON)
	{
		pos = game->player->pos->x;
		body = (dx < 0) ? -1 * game->settings->body :
			game->settings->body;
		if (game->map->map[(int)(game->player->pos->y) /
				game->settings->sq_size]
				[(int)(pos + dx + body) /
				game->settings->sq_size] == '1')
			return ;
	}
	game->player->pos->x += dx;
}

static void	coll_y(t_game *game, float dy)
{
	float	pos;
	float	body;

	if (game->settings->settings & SETT_COLL_ON)
	{
		pos = game->player->pos->y;
		body = (dy < 0) ? -1 * game->settings->body :
			game->settings->body;
		if (game->map->map[(int)(pos + dy + body) /
				game->settings->sq_size]
				[(int)(game->player->pos->x) /
				game->settings->sq_size] == '1')
			return ;
	}
	game->player->pos->y += dy;
}

static void	collisions(t_game *game, float dx, float dy)
{
	coll_x(game, dx);
	coll_y(game, dy);
}

void		movement(t_game *game)
{
	float		a;

	a = game->player->angle;
	if (game->player->move_flags & MOVE_FLAG_FORW)
		collisions(game, game->player->move_speed * cos(a),
				game->player->move_speed * sin(a));
	if (game->player->move_flags & MOVE_FLAG_BACK)
		collisions(game, -1 * game->player->move_speed * cos(a),
				-1 * game->player->move_speed * sin(a));
	if (game->player->move_flags & MOVE_FLAG_LEFT)
		collisions(game, game->player->move_speed * sin(a),
				-1 * game->player->move_speed * cos(a));
	if (game->player->move_flags & MOVE_FLAG_RIGHT)
		collisions(game, -1 * game->player->move_speed * sin(a),
				game->player->move_speed * cos(a));
	if (game->player->move_flags & MOVE_FLAG_ROT_L)
		rotate(game, 1);
	if (game->player->move_flags & MOVE_FLAG_ROT_R)
		rotate(game, 0);
}
