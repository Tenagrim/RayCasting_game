#include <cub3d.h>

int exit_game(t_game *game, int code)
{
	if (!game)
		code = -1;
	//clear_config(&game->config);
	//clear_window(&game->window);
	//clear_textures(game);
	//clear_sprites(&game->sprites);
	ft_printf("Exiting with code: %d\n", code); //FIXME write to stderr

	ft_printf(">>%p\n", game->mlx->mlx_ptr);
	if (game)
	{
		mlx_do_key_autorepeaton(game->mlx->mlx_ptr);
		ft_printf("repeat_on\n");
	}
	exit(code);
	return (code);
}
