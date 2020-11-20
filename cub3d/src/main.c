#include <cub3d.h>

static t_game	*init_game(char **av)
{
	t_mlx		*mlx;
	t_game		*game;
	t_map		*map;
	t_list		*file;

	file = NULL;
	game = (t_game*)malloc(sizeof(t_game));
	game->settings = ft_default_settings();
	game->player = ft_new_player();
	file = ft_read_file(av[1]);
	map = ft_get_map_from_file(file);
	ft_print_map(map);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	//ft_print_file(file);
	game->map = map;
	game->mlx = mlx;
	mlx->mlx_ptr = mlx_init();
	//ft_printf("{%d}\n", X_EVENT_KEY_PRESS);
	mlx->win= mlx_new_window(mlx->mlx_ptr, map->win_width, map->win_height, WIN_NAME);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, map->win_width, map->win_height);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &game);
	mlx_hook(mlx->win, X_EVENT_KEY_RELEASE, 1L<<0, &key_release, &game);
	mlx_hook(mlx->win, X_EVENT_EXIT, 0L, &exit_hook, &mlx);
	return (game);
}

int		main(int ac, char **av)
{
	t_game		*game;

	if (!ac || !av)
		return (1);
	game = init_game(av);
	//mlx_loop_hook(game->mlx->mlx_ptr, &ft_main_loop, &game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
