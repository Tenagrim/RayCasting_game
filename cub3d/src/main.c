#include <cub3d.h>

static t_game	*init_game(char **av)
{
	t_mlx		*mlx;
	t_game		*game;
	t_map		*map;

	game = (t_game*)malloc(sizeof(t_game));
	game->settings = ft_default_settings();
	game->player = ft_new_player();
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	game->mlx = mlx;
	if (!(map = ft_get_map_from_file(game, av[1])))
		return (NULL);
	game->map = map;
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, game->settings->win_size->x, game->settings->win_size->y);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &(mlx->img->bpp), &(mlx->img->size_l), &(mlx->img->endian));
	mlx->win= mlx_new_window(mlx->mlx_ptr, game->settings->win_size->x, game->settings->win_size->y, WIN_NAME);
	mlx_hook(mlx->win, 2, 1L<<0, &key_press, game);
	mlx_hook(mlx->win, 3, 1L<<1, &key_release, game);
	mlx_hook(mlx->win, X_EVENT_EXIT, 0, &exit_hook, game);
	mlx_do_key_autorepeatoff(mlx->mlx_ptr);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, mlx->img->img_ptr, 0, 0);
	return (game);
}

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
