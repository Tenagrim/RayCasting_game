#include <cub3d.h>

int exit_game(t_game *game, int code)
{
	if (!game)
		code = -1;
	ft_printf("Exiting with code: %d\n", code); //FIXME write to stderr

	ft_printf(">>%p\n", game->mlx->mlx_ptr);
	if (game)
	{
		mlx_do_key_autorepeaton(game->mlx->mlx_ptr);
		clear_game(&game);
		ft_printf("repeat_on\n");
	}
	exit(code);
	return (code);
}
