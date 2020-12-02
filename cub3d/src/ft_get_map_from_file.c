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

static int		map_get_tex_ind(char *dir)
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
	ind = map_get_tex_ind(dir);
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

static int		get_color(char *line)
{
	char	**digits;
	int	r;
	int	g;
	int	b;

	digits = ft_split(line + 2, ','); // FIXME need to be freed
	r = ft_atoi(digits[0]);
	g = ft_atoi(digits[1]);
	b = ft_atoi(digits[2]);
	if (r < 0 || r  > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

static int		parse_f_color(t_game *game, t_list *file)
{
	char	*line;
	int	color;

	line = find_line(file, "F ");
	if (!line)
		return (0);
	color = get_color(line);
	if (color == -1)
		return (0);
	game->settings->floor_color = color;
	return (1);
}

static int		parse_c_color(t_game *game, t_list *file)
{
	char	*line;
	int	color;

	line = find_line(file, "C ");
	if (!line)
		return (0);
	color = get_color(line);
	if (color == -1)
		return (0);
	game->settings->ceil_color= color;
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

static int		valid_map_line(char *line)
{
	if (!(*line))
		return (0);
	while (*line)
	{
		if (!ft_strchr(MAP_CHARS, *line))
			return (0);
		line++;
	}
	return (1);
}

static int		parse_map_size(t_list *file, t_list **map_firstline, t_intpair *map_size)
{
	t_list		*p;
	int		tmp;

	p = file;
	while (p && !valid_map_line((char*)(p->content)))
		p = p->next;
	if (!p)
		return (0);
	*map_firstline = p;
	map_size->y = 0;
	map_size->x = ft_strlen((char*)(p->content));
	while (p && valid_map_line((char*)(p->content)))
	{
		tmp = ft_strlen((char*)(p->content));
		map_size->x = FT_MAX(map_size->x, tmp);
		map_size->y++;
		p = p->next;
	}
	return (1);
}

static int		parse_map(t_game *game, t_list *file)
{
	t_list	*map_firstline;
	t_list	*p;
	char	**res;
	int	i;

	if (!parse_map_size(file, &map_firstline, game->map->map_size))
		return (0);
	res = (char**)malloc(sizeof(char*) * game->map->map_size->y);
	i = 0;
	p = map_firstline;
	while (i < game->map->map_size->y)
	{
		res[i] = ft_calloc(game->map->map_size->x, sizeof(char));
		ft_strcpy(res[i], (char*)(p->content));
		p = p->next;
		i++;
	}
	game->map->map = res;
	return (1);
}

static int		get_pl_pos(t_game *game, char c, int i, int j)
{
	if (c && ft_strchr(MAP_DIRS_CHARS, c))
	{
		ft_printf("char = [%d]\n", c);
		if (game->settings->parse_finds & PARSE_PL_POS_FOUND)
		{
			ft_printf("exit -1\n");
			return (-1);
		}
		game->settings->parse_finds |= PARSE_PL_POS_FOUND;
		if (c == 'N')
			game->player->angle =  M_PI * 2 - M_PI / 2;
		else if (c == 'E')
			game->player->angle =  0.0;
		else if (c == 'S')
			game->player->angle =  M_PI / 2;
		else if (c == 'W')
			game->player->angle =  M_PI;
		game->player->pos->x = j * game->settings->sq_size + game->settings->sq_size / 2 + 1;
		game->player->pos->y = i * game->settings->sq_size + game->settings->sq_size / 2 + 1;
	}
	return (0);
}

static int		valid_map(t_game *game)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < game->map->map_size->y)
	{
		j = 0;
		while (j < game->map->map_size->x)
		{
			c = game->map->map[i][j];
			if ((get_pl_pos(game, c, i, j)) == -1)
			{
				ft_printf(">>>[%d][%s]\n",c, game->map->map[i]);
				return (0);
			}
			j++;
		}
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
	res->map_size = ft_new_intpair(0, 0);
	game->map = res;
	if (!(parse_f_color(game, file) && parse_c_color(game, file)))
		return (0);
	if (parse_tex_paths(game, file) && parse_res(game, file) && parse_map(game, file) && valid_map(game) && validate_map(game->map))
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
