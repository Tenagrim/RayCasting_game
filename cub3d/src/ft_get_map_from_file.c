#include <cub3d.h>

static char		**gen_map(void)
{
	char	**res;

	res = (char**)malloc(sizeof(char*) * 16);
	res[0] = ft_strdup("11111111111111111111111111111");
	res[1] = ft_strdup("10000000100000000000000000001");
	res[2] = ft_strdup("10111110100000000000011100001");
	res[3] = ft_strdup("10000000101000000000000100001");
	res[4] = ft_strdup("10000000010000010101000100001");
	res[5] = ft_strdup("10100111000010000000001100001");
	res[6] = ft_strdup("10100111000010001010100100001");
	res[7] = ft_strdup("10100111001000000000011100001");
	res[8] = ft_strdup("10110000001110001010101100001");
	res[9] = ft_strdup("10010011110100000000000100001");
	res[10] = ft_strdup("10100000000000000000000000001");
	res[11] = ft_strdup("10101011000111110000000000001");
	res[12] = ft_strdup("10001011101110110000000000001");
	res[13] = ft_strdup("10101000000000010000000000001");
	res[14] = ft_strdup("10000000000000000000000000001");
	res[15] = ft_strdup("11111111111111111111111111111");
	return (res);
}

static t_list		*get_walls(t_map *map)
{
	int	i;
	int	j;
	t_list	*res;

	res = NULL;
	i = 0;
	while (i < map->map_size->y)
	{
		j = 0;
		while (j < map->map_size->x)
		{
			if (map->map[i][j] == '1')
			{
				ft_lstadd_front(&res, ft_lstnew((void *)ft_new_intpair(j, i)));
				//ft_printf("wall: %d   %d\n", j, i);
			}
			j++;
		}
		i++;
	}
	return (res);
}

static int		get_tex_ind(char *dir)
{
	if (!ft_strcmp(dir, "NO"))
		return (0);
	else if (!ft_strcmp(dir, "WE"))
		return (1);
	else if (!ft_strcmp(dir, "SO"))
		return (2);
	else if (!ft_strcmp(dir, "EA"))
		return (3);
	else if (!ft_strcmp(dir, "S"))
		return (4);
	return (-1);
}

static int		get_tex_path(t_game *game, t_list *file, char *dir)
{
	t_list *p;
	int	ind;

	p = file;
	ind = get_tex_ind(dir);
	while (p)
	{
		if (ft_strncmp((char*)(p->content), dir, 2))
		{
			if (game->settings->parse_finds & 1 << (ind + 1))
				return (0);
			game->settings->parse_finds |= 1 << (ind + 1);
			game->map->texture_paths[ind] = ft_strdup((char*)(p->content) + ft_strlen(dir));
			return (1);
		}
		p = p->next;
	}
	return (0);
}

static int		parse_tex_paths(t_game *game, t_list *file)
{
	if (get_tex_path(game, file, "NO") &&
			get_tex_path(game, file, "WE") &&
			get_tex_path(game, file, "SO") &&
			get_tex_path(game, file, "EA") &&
			get_tex_path(game, file, "S"))
		return (1);
	return (0);
}

static int		parse_res(t_game *game, t_list *file)
{
	
}

t_map			*ft_get_map_from_file(t_game *game, char *filename)
{
	t_map	*res;
	t_list	*file;

	file = ft_read_file(filename);
	if (!file)
		return (0); //FIXME
	res = (t_map *)malloc(sizeof(t_map));
	res->textures = (t_img **)malloc(sizeof(t_img*) * 5);
	res->texture_paths = (char **)malloc(sizeof(char) * 5);
	res->map = gen_map();
	res->map_size = ft_new_intpair(ft_strlen(res->map[0]), 16);
	res->walls = get_walls(res);
	return (res);
}
