#include <cub3d.h>

int key_release(int keycode, t_game *game)
{
	if (!game)
		return (0);
	if (keycode == KEYS_ESC)
		return (exit_game(game, EXIT_SUCCESS));	
	ft_printf("key code: %d\n", keycode);
	return (0);
}
