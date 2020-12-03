#include <cub3d.h>

static int	ft_free_local(t_intpair *a, t_intpair *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}


static float ft_map_zero(float x, float in_max, float out_max)
{
  return x * out_max  / in_max;
}



static void	crop_vert(t_game *game, t_intpair *pos,
		t_intpair *coords, int *low_stop)
{
	if (pos->y < 0)
	{
		coords->y += -(pos->y);
		*low_stop = game->settings->win_size->y;
	}
}

static void	crop_hor(t_game *game, t_intpair *pos, t_intpair *size)
{
	if (pos->x + size->x >= game->settings->win_size->x)
		size->x = size->x - (pos->x + size->x -
				game->settings->win_size->x);
}

int		draw_textured_rectangle(t_game *game,
		t_intpair *pos, t_intpair *size, t_img *tex)
{
	t_intpair	coords;
	t_intpair	t_pos;
	int		low_stop;
	unsigned int	c;

	coords.y = pos->y;
	low_stop = pos->y + size->y;
	crop_vert(game, pos, &coords, &low_stop);
	crop_hor(game, pos, size);
	while (coords.y < low_stop)
	{
		coords.x = pos->x;
		while (coords.x < size->x + pos->x)
		{
			t_pos.x = ((coords.x - pos->x) / size->x) + tex->offset;
			t_pos.y = ft_map_zero(coords.y - pos->y, size->y, tex->height);
			c = tex->data[t_pos.y * tex->width + t_pos.x];
			if (c != 0xff980088)
				game->mlx->img->data[coords.y *
					game->settings->win_size->x + coords.x] = c;
			coords.x++;
		}
		coords.y++;
	}
	return (ft_free_local(pos, size));
}

