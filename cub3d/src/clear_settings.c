#include <cub3d.h>

void		clear_settings(t_game *game)
{
	if (!(game->settings))
		return ;
	if (game->settings->z_buffer)
		free(game->settings->z_buffer);
	if (game->settings->texture_size)
		free(game->settings->texture_size);
	if (game->settings->win_size)
		free(game->settings->win_size);
	free(game->settings);
	game->settings = NULL;
}
