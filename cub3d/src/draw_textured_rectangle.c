#include <cub3d.h>

static int	ft_free_local(t_intpair *a, t_intpair *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}
/*
static float ft_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static float ft_map_r(int x, t_intpair *range_in, t_intpair *range_out)
{
  return (x - range_in->x) * (range_out->y - range_out->x) / (range_in->y - range_in->x) + range_out->x;
}
*/
static float ft_map_zero(float x, float in_max, float out_max)
{
  return x * out_max  / in_max;
}


/*
static void	ft_crop(t_game *game, t_intpair *pos, t_intpair *size, t_intpair *texture_size)
{
	float	rem;

	texture_size->x = 0;
	texture_size->y = game->settings->texture_size->y;
	if (pos->y < 0)
	{
		rem = ft_map_zero(-(pos->y), size->y, game->settings->texture_size->y);
		texture_size->x = floor(rem);
		texture_size->y = game->settings->texture_size->y - rem * 2;
		pos->y = 0;
		size->y = game->settings->win_size->y - 1;
	}
	pos->x = (pos->x < 0) ? 0 : pos->x;
	size->x = (size->x + pos->x >= game->settings->win_size->x) ?
		game->settings->win_size->x - pos->x  : size->x;
	//size->y = (size->y + pos->y >= game->settings->win_size->y) ?
	//	 -1 : size->y;
}
*/
static void	crop_vert(t_game *game, t_intpair *pos, t_intpair *coords, int *low_stop)
{
	if (pos->y < 0)
	{
		coords->y += -(pos->y);
		*low_stop = game->settings->win_size->y - 1;
	}
}

int		draw_textured_rectangle(t_game *game, t_intpair *pos, t_intpair *size, t_img *texture)
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
			t_pos.x = ((coords.x - pos->x) / game->settings->scale) + texture->offset;
			t_pos.y = ft_map_zero(coords.y - pos->y, size->y, texture->height);
			c = texture->data[t_pos.y * texture->width + t_pos.x];
			c = (game->settings->settings & SETT_SHADOWS_ON) ? FT_MAX(0, ((((c & 0xFF0000) >> 16) - texture->shadow)<<16)) | FT_MAX(0 ,((((c & 0x00FF00) >> 8) - texture->shadow) << 8)) | FT_MAX(0,((c & 0x0000FF) - texture->shadow)) : c;
			game->mlx->img->data[coords.y * game->settings->win_size->x + coords.x] = c;
			coords.x++;
		}
		coords.y++;
	}
	return (ft_free_local(pos, size));
}

