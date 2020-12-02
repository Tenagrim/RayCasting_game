#include <cub3d.h>

static void		get_walls(t_game *game)
{
	int		i;
	int		j;
	t_map		*map;
	t_list		*res;
	t_sprite	*sprites;

	res = NULL;
	sprites = NULL;
	map = game->map;
	i = 0;
	while (i < map->map_size->y)
	{
		j = 0;
		while (j < map->map_size->x)
		{
			if (map->map[i][j] == '1')
				ft_lstadd_front(&res, ft_lstnew((void *)ft_new_intpair(j, i)));
			if (map->map[i][j] == '2')
				ft_sprtadd_front(&sprites, ft_sprtnew(ft_new_floatpair(j * game->settings->sq_size + game->settings->sq_size / 2 , i * game->settings->sq_size + game->settings->sq_size / 2)));
			j++;
		}
		i++;
	}
	map->walls = res;
	map->sprites = sprites;
}






t_map			*ft_get_map_from_file(t_game *game, char *filename)
{
	t_map	*res;
	t_list	*file;

	file = ft_read_file(filename);
	if (!file)
		return (0); //FIXME
	if (!(res = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	res->textures = (t_img **)malloc(sizeof(t_img*) * 5);
	res->texture_paths = (char **)malloc(sizeof(char*) * 5);
	res->map_size = ft_new_intpair(0, 0);
	game->map = res;
	if (!(parse_f_color(game, file) && parse_c_color(game, file)))
		return (0);
	if (parse_tex_paths(game, file) && parse_res(game, file) && parse_map(game, file) && get_player_pos(game) && validate_map(game->map))
	{
		get_walls(game);
		ft_get_settings(game);
		if (!load_textures(game))
			return (NULL);
		return (res);
	}
	else
		return NULL;
}
