#include <cub3d.h>

static int	ft_free_local(t_intpair *a, t_intpair *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}

int		draw_rectangle(t_game *game, t_intpair *pos, t_intpair *size, int color)
{
	t_img	*img;
	int	x;
	int	y;
	int	width;
	int	height;
	
	width = game->settings->win_size->x;
	height = game->settings->win_size->y;
	pos->x = (pos->x < 0) ? 0 : pos->x;
	pos->y = (pos->y < 0) ? 0 : pos->y;
	//if (pos->x < 0 || pos->y + size->y >= height || pos->y < 0 || pos->x + size->x >=width)
	//	return (ft_free_local(pos, size));
	img = game->mlx->img;
	y = pos->y;
	while (y < size->y + pos->y)
	{	
		if (y >= 0 && y < height)
		{
			x = pos->x;
			while (x < size->x + pos->x)
			{
				if (x >= 0 && x < width)
					img->data[y * width + x] = color;
				x++;
			}
		}
		y++;
	}
	return (ft_free_local(pos, size));
}
