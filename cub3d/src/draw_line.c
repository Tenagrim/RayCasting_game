#include <cub3d.h>

static int	ft_free_local(t_intpair *a, t_intpair *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}

static void	crop(t_game *game, t_intpair *start, t_intpair *stop)
{
	int width;
	int heigth;

	width = game->settings->win_size->x;
	heigth = game->settings->win_size->y;
	start->x = (start->x < 0) ? 0 : start->x;
	start->y = (start->y < 0) ? 0 : start->y;
	start->x = (start->x >= width) ? width - 1 : start->x;
	start->y = (start->y >= heigth) ? heigth - 1 : start->y;
	stop->x = (stop->x < 0) ? 0 : stop->x;
	stop->y = (stop->y < 0) ? 0 : stop->y;
	stop->x = (stop->x >= width) ? width - 1 : stop->x;
	stop->y = (stop->y >= heigth) ? heigth - 1 : stop->y;
}

int		draw_line(t_game *game, t_intpair *start, t_intpair *stop, int color)
{
	t_intpair	d;
	t_intpair	s;
	int		err;
	int		e2;

	crop(game, start, stop);
	d.x = ft_abs(stop->x - start->x);
	d.y = -ft_abs(stop->y - start->y);
	s.x = (start->x < stop->x) ? 1 : -1;
	s.y = (start->y < stop->y) ? 1 : -1;
	err = d.x + d.y;
	while (1)
	{
		draw_pixel(game, start->x, start->y, color);
		if (start->x == stop->x && start->y == stop->y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			start->x = start->x + s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			start->y = start->y + s.y;
		}
	}
	return (ft_free_local(start, stop));
}
