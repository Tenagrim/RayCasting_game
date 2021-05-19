#include <cub3d.h>

static int		get_color(char *line)
{
	char	**digits;
	int		r;
	int		g;
	int		b;

	digits = ft_split(line + 2, ',');
	if (!digits || ft_count_splitted(digits) != 3)
		return (ft_clear_split(&digits) - 1);
	r = ft_atoi(digits[0]);
	g = ft_atoi(digits[1]);
	b = ft_atoi(digits[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_clear_split(&digits) - 1);
	ft_clear_split(&digits);
	return (r << 16 | g << 8 | b);
}

int				parse_f_color(t_game *game, t_list *file)
{
	char	*line;
	int		color;

	line = find_line(file, "F ");
	if (!line)
		return (0);
	color = get_color(line);
	if (color == -1)
		return (0);
	game->settings->floor_color = color;
	return (1);
}

int				parse_c_color(t_game *game, t_list *file)
{
	char	*line;
	int		color;

	line = find_line(file, "C ");
	if (!line)
		return (0);
	color = get_color(line);
	if (color == -1)
		return (0);
	game->settings->ceil_color = color;
	return (1);
}
