#include <cub3d.h>

void		clear_player(t_game *game)
{
	if (!(game->player))
		return ;
	if (game->player->pos)
		free(game->player->pos);
	free(game->player);
	game->player = NULL;
}
