#include <cub3d.h>

/*
** ft_printf("key released code: %d\n", keycode);
*/

int	key_release(int keycode, t_game *game)
{
	if (keycode < 0 || !game)
		return (0);
	if (keycode == KEYS_ESC)
		return (exit_game(game, EXIT_SUCCESS));
	else if (keycode == KEYS_W)
		game->player->move_flags &= ~(MOVE_FLAG_FORW);
	else if (keycode == KEYS_S)
		game->player->move_flags &= ~(MOVE_FLAG_BACK);
	else if (keycode == KEYS_A)
		game->player->move_flags &= ~(MOVE_FLAG_LEFT);
	else if (keycode == KEYS_D)
		game->player->move_flags &= ~(MOVE_FLAG_RIGHT);
	else if (keycode == KEYS_L_ARROW)
		game->player->move_flags &= ~(MOVE_FLAG_ROT_L);
	else if (keycode == KEYS_R_ARROW)
		game->player->move_flags &= ~(MOVE_FLAG_ROT_R);
	else if (keycode == KEYS_L_SHIFT)
		game->player->move_speed = game->player->walk_speed;
	return (0);
}
