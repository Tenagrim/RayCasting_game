#include <cub3d.h>

int exit_game(t_game *game, int code)
{
	if (!game)
		code = -1;
	//clear_config(&game->config);
	//clear_window(&game->window);
	//clear_textures(game);
	//clear_sprites(&game->sprites);
	exit(code);
	return (code);
}
