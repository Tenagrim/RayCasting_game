#include <cub3d.h>

int		main(int ac, char **av)
{
	t_game		*game;

	game = NULL;
	if (ac < 2 || ac > 3)
		exit_game(game, 1);

	if (!(game = init_game(av)))
		return (0);
	mlx_loop_hook(game->mlx->mlx_ptr, &ft_main_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
