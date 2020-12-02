#include <cub3d.h>

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

int		parse_map(t_game *game, t_list *file)
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
