#include <cub3d.h>

int	exit_hook(t_game *game)
{
	ft_printf("exit hook\n");
	return (exit_game(game, EXIT_SUCCESS));
}
