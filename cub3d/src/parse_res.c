#include <cub3d.h>

int		parse_res(t_game *game, t_list *file)
{
	char		*line;
	char		**digits;
	t_intpair	res;

	line = find_line(file, "R ");
	if (game->settings->parse_finds & PARSE_RES_FOUND || !line)
		return (0);
	digits = ft_split(line + 2, ' ');
	if (!digits || ft_count_splitted(digits) != 2)
		return (ft_clear_split(&digits));
	res.x = ft_atoi(digits[0]);
	res.y = ft_atoi(digits[1]);
	ft_clear_split(&digits);
	if (res.x <= 0 || res.y <= 0)
		return (0);
	game->settings->win_size->x = FT_MIN(res.x, game->settings->win_max->x);
	game->settings->win_size->y = FT_MIN(res.y, game->settings->win_max->y);
	return (1);
}
