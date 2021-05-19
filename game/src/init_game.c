#include <cub3d.h>

static t_game	*start(void)
{
	t_game		*game;

	if (!(game = (t_game*)malloc(sizeof(t_game))))
		return (NULL);
	game->mlx = NULL;
	game->settings = NULL;
	game->player = NULL;
	game->map = NULL;
	return (game);
}

static t_game	*abort_l(t_game *game)
{
	clear_game(&game);
	return (NULL);
}

static int		init_img(t_game *game)
{
	t_mlx *mlx;

	mlx = game->mlx;
	if (!(mlx->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr,
			game->settings->win_size->x,
			game->settings->win_size->y);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr,
			&(mlx->img->bpp), &(mlx->img->size_l),
			&(mlx->img->endian));
	return (1);
}

t_game			*init_game(char **av)
{
	t_mlx		*mlx;
	t_game		*game;

	if (!(game = start()))
		return (NULL);
	game->settings = ft_default_settings();
	game->player = ft_new_player();
	if (!(mlx = init_mlx()))
		return (abort_l(game));
	mlx->mlx_ptr = mlx_init();
	game->mlx = mlx;
	if (!(game->map = ft_get_map_from_file(game, av[1])))
		return (abort_l(game));
	if (!(init_img(game)))
		return (abort_l(game));
	mlx->win = mlx_new_window(mlx->mlx_ptr, game->settings->win_size->x,
			game->settings->win_size->y, WIN_NAME);
	mlx_hook(mlx->win, 2, 1L << 0, &key_press, game);
	mlx_hook(mlx->win, 3, 1L << 1, &key_release, game);
	mlx_hook(mlx->win, X_EVENT_EXIT, 0, &exit_hook, game);
	mlx_do_key_autorepeatoff(mlx->mlx_ptr);
	return (game);
}

/*
**mlx_get_screen_size(mlx->mlx_ptr, &(game->settings->win_max->x),
**&(game->settings->win_max->y));
*/
