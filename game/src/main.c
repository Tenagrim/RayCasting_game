#include <cub3d.h>

int		main(int ac, char **av)
{
	t_game		*game;
	int			save;

	game = NULL;
	save = (ac == 3 && !ft_strcmp(av[2], "--save"));
	if (ac != 2 + save)
		exit_game(game, -5);
	if (!check_filename(av[1]))
	{
		ft_printf("Error\n Wrong file: %s\n", av[1]);
		exit_game(game, -6);
	}
	if (!(game = init_game(av)))
		return (exit_game(game, -2));
	if (save)
		return (screenshot(game));
	mlx_loop_hook(game->mlx->mlx_ptr, &ft_main_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
