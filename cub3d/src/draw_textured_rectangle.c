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



static void	crop_vert(t_game *game, t_intpair *pos, t_intpair *coords, int *low_stop)
{
	if (pos->y < 0)
	{
		coords->y += -(pos->y);
		*low_stop = game->settings->win_size->y;
	}
}

int		draw_textured_rectangle(t_game *game, t_intpair *pos, t_intpair *size, t_img *tex)
{
	t_intpair	coords;
	t_intpair	t_pos;
	int		low_stop;
	int		c;

	coords.y = pos->y;
	low_stop = pos->y + size->y;
	crop_vert(game, pos, &coords, &low_stop);
	while (coords.y < low_stop)
	{
		coords.x = pos->x;
		while (coords.x < size->x + pos->x)
		{
			t_pos.x = ((coords.x - pos->x) / size->x) + tex->offset;
			t_pos.y = ft_map_zero(coords.y - pos->y, size->y, tex->height);
			c = tex->data[t_pos.y * tex->width + t_pos.x];
			if (c != 0xff980088)
			{
				c = (game->settings->settings & SETT_SHADOWS_ON) ?
				FT_MAX(0, ((((c & 0xFF0000) >> 16) - tex->shadow) << 16)) |
				FT_MAX(0, ((((c & 0x00FF00) >> 8) - tex->shadow) << 8)) |
				FT_MAX(0, ((c & 0x0000FF) - tex->shadow)) : c;
				game->mlx->img->data[coords.y * game->settings->win_size->x + coords.x] = c;
			}
			coords.x++;
		}
		coords.y++;
	}
	return (ft_free_local(pos, size));
}

