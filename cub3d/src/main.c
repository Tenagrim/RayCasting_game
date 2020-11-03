#include <cub3d.h>



int		main(int ac, char **av)
{
	t_mlx		*mlx;
	t_map		*map;
	t_list		*file;
	t_game		*game;

	if (!ac || !av)
		return (1);
	file = NULL;
	game = (t_game*)malloc(sizeof(t_game));
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	map = ft_get_map_from_file(file);
	game->map = map;
	game->mlx = mlx;
	mlx->mlx_ptr = mlx_init();
	mlx->win= mlx_new_window(mlx->mlx_ptr, map->win_width, map->win_height, WIN_NAME);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, map->win_width, map->win_height);

	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(mlx->win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(mlx->win, X_EVENT_EXIT, 0, &exit_hook, &mlx);
	//mlx_loop_hook(game.window.ptr, &main_loop, &game);

	mlx_loop(mlx->mlx_ptr);	
	return (0);
}
