#include <cub3d.h>



//img->data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;

int	key_press(int keycode, t_game *game)
{
	if(!keycode || !game)
		return (0);
	ft_printf("key pressed  code: %d\n", keycode);
	if (keycode == KEYS_W)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_FORW;
	else if (keycode == KEYS_S)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_BACK;
	else if (keycode == KEYS_A)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_LEFT;
	else if (keycode == KEYS_D)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_RIGHT;
	else if (keycode == KEYS_L_ARROW)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_ROT_L;
	else if (keycode == KEYS_R_ARROW)
		game->player->move_flags = game->player->move_flags | MOVE_FLAG_ROT_R;
	else if (keycode == KEYS_L_SHIFT)
		game->player->move_speed = game->player->run_speed;
	return (0);
}
