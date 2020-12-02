#include <cub3d.h>

static t_map		*abort_l(t_game *game)
{
	clear_textures(game);
	clear_map(&(game->map));
	return (NULL);
}

static void		get_sprites(t_game *game)
{
	int		i;
	int		j;
	t_map		*map;
	int		size;
	t_sprite	*sprites;

	sprites = NULL;
	map = game->map;
	i = 0;
	size = game->settings->sq_size;
	while (i < map->map_size->y)
	{
		j = 0;
		while (j < map->map_size->x)
		{
			if (map->map[i][j] == '2')
				ft_sprtadd_front(&sprites,
				ft_sprtnew(ft_new_floatpair(j * size + size / 2,
				i * size + size / 2)));
			j++;
		}
		i++;
	}
	map->sprites = sprites;
}

t_map			*ft_get_map_from_file(t_game *game, char *filename)
{
	t_map	*res;
	t_list	*file;

	file = ft_read_file(filename);
	if (!file)
		return (0);
	if (!(res = init_map()))
		return (NULL);
	game->map = res;
	if (parse_f_color(game, file) && parse_c_color(game, file) &&
			parse_tex_paths(game, file) && parse_res(game, file) &&
			parse_map(game, file) && get_player_pos(game) &&
			validate_map(game->map) && load_textures(game))
	{
		get_sprites(game);
		ft_get_settings(game);
		return (res);
	}
	else
		return (abort_l(game));
}
