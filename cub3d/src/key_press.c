#include <cub3d.h>

int	key_press(int keycode, t_game *game)
{
	if(!keycode || !game)
		return (0);
	ft_printf("key pressed code: %d\n", keycode);
	return (0);
}
