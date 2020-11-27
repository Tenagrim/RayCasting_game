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
			}
			j++;
		}
		i++;
	}
	return (res);
}

static int		get_tex_ind(char *dir)
{
	if (!ft_strcmp(dir, "NO "))
		return (0);
	else if (!ft_strcmp(dir, "WE "))
		return (1);
	else if (!ft_strcmp(dir, "SO "))
		return (2);
	else if (!ft_strcmp(dir, "EA "))
		return (3);
	else if (!ft_strcmp(dir, "S "))
		return (4);
	return (-1);
}

static char		*find_line(t_list *file, char *key)
{
	t_list *p;
	char	*res;
	char	*susp;

	p = file;
	res = NULL;
	while (p)
	{
		susp = (char *)(p->content);
		if (!ft_strncmp(susp, key, ft_strlen(key)))
			return (susp);
		p = p->next;
	}
	return (res);
}

static int		get_tex_path(t_game *game, t_list *file, char *dir)
{
	int	ind;
	char	*line;

	line = find_line(file, dir);
	ind = get_tex_ind(dir);
	if (game->settings->parse_finds & 1 << (ind + 1) || !line)
		return (0);
	game->settings->parse_finds |= 1 << (ind + 1);
	game->map->texture_paths[ind] = ft_strdup(line + ft_strlen(dir));
	return (1);
}

static int		parse_tex_paths(t_game *game, t_list *file)
{
	if (get_tex_path(game, file, "NO ") &&
			get_tex_path(game, file, "WE ") &&
			get_tex_path(game, file, "SO ") &&
			get_tex_path(game, file, "EA ") &&
			get_tex_path(game, file, "S "))
		return (1);
	return (0);
}

static int		parse_res(t_game *game, t_list *file)
{
	char		*line;
	char		**digits; 	//FIXME need to free
	t_intpair	res;

	line = find_line(file, "R ");
	if (game->settings->parse_finds & PARSE_RES_FOUND || !line)
		return (0);
	digits = ft_split(line + 2, ' ');
	res.x = ft_atoi(digits[0]);
	res.y = ft_atoi(digits[1]);
	if (res.x <= 0 || res.y <= 0)
		return (0);
	game->settings->win_size->x = res.x;
	game->settings->win_size->y = res.y;
	return (1);
}

static int		load_textures(t_game *game)
{
	int	i;
	t_img	*img;
	i = 0;
	while (i < 5)
	{
		img = load_texture(game, game->map->texture_paths[i]);
		if (!img)
			return (0);
		game->map->textures[i] = img;
		i++;
	}
	return (1);
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
	res->map = gen_map();
	res->map_size = ft_new_intpair(ft_strlen(res->map[0]), 16);
	res->walls = get_walls(res);
	game->map = res;
	if (parse_tex_paths(game, file) && parse_res(game, file))
	{
		ft_printf("textures: \n");
		ft_printf("[%s]\n", res->texture_paths[0]);
		ft_printf("[%s]\n", res->texture_paths[1]);
		ft_printf("[%s]\n", res->texture_paths[2]);
		ft_printf("[%s]\n", res->texture_paths[3]);
		ft_printf("[%s]\n", res->texture_paths[4]);
		if (!load_textures(game))
			return (NULL);
		return (res);
	}
	else
		return NULL;
}
