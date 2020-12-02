#include <cub3d.h>

void	rotate(t_game *game, char dir)
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

void	movement(t_game *game)
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

