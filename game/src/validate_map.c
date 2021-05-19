#include <cub3d.h>

static int	is_hole(char c)
{
	return (c == ' ' || c == 0);
}

static int	is_floor(char c)
{
	return (c == '0' || c == '2' ||
			c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

static int	horizontals(t_map *map)
{
	int		i;
	int		j;
	char	prev;
	char	cur;

	i = 0;
	while (i < map->map_size->y)
	{
		j = 1;
		prev = map->map[i][0];
		while (j < map->map_size->x)
		{
			cur = map->map[i][j];
			if ((is_hole(prev) && is_floor(cur)) ||
					((is_hole(cur) && is_floor(prev))) ||
					(is_floor(prev) && j == 1))
				return (error_map_line(i, map->map[i], 'h'));
			prev = cur;
			j++;
		}
		i++;
	}
	return (1);
}

static int	verticals(t_map *map)
{
	int		i;
	int		j;
	char	prev;
	char	cur;

	i = 0;
	while (i < map->map_size->x)
	{
		j = 1;
		prev = map->map[0][i];
		while (j < map->map_size->y)
		{
			cur = map->map[j][i];
			if ((is_hole(prev) && is_floor(cur)) ||
					((is_hole(cur) && is_floor(prev))) ||
					(is_floor(cur) && j ==
					map->map_size->y - 1) ||
					(is_floor(prev) && j == 1))
				return (error_map_line(j, map->map[j], 'v'));
			prev = cur;
			j++;
		}
		i++;
	}
	return (1);
}

int			validate_map(t_map *map)
{
	return (horizontals(map) && verticals(map));
}
