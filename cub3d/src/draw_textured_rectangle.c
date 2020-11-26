#include <cub3d.h>

static int	ft_free_local(t_intpair *a, t_intpair *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}

static int	get_texture_color(t_img *texture, int x, int y)
{
	return (texture->data[y * texture->width + x]);
}

static float ft_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int		draw_textured_rectangle(t_game *game, t_intpair *pos, t_intpair *size, t_img *texture)
{
	t_img	*img;
	int	x;
	int	y;
	int	width;
	int	height;
	int	t_x;
	int	t_y;
	int	c;
	
	width = game->settings->win_size->x;
	height = game->settings->win_size->y;
	//pos->x = (pos->x < 0) ? 0 : pos->x;
	//pos->y = (pos->y < 0) ? 0 : pos->y;
	//size->x = (size->x + pos->x >= width) ? width - pos->x -1 : size->x;
	//size->y = (size->y + pos->y >= height) ? height - pos->y -1 : size->y;
	img = game->mlx->img;
	y = pos->y;
	//size->x = 1;
	while (y < size->y + pos->y)
	{	
		x = pos->x;
		if (y >= 0 && y < height)
		while (x < size->x + pos->x)
		{
			if (x >= 0 && x < width)
			{
				t_x =  1 + texture->offset * 64.0 /game->settings->sq_size;
				//t_x =  ft_map(x - pos->x, 0, size->x, 0, game->settings->texture_scale) + texture->offset * game->settings->texture_scale;
				//t_x =  ft_map(x - pos->x, 0, size->x, 0, 64.0 / size->y) + (int)texture->offset * 64.0/ size->y;
				t_y = ft_map(y - pos->y, 0, size->y, 0, 64);
				c = get_texture_color(texture, t_x, t_y);
				img->data[y * width + x] = ft_max(0, ((((c & 0xFF0000) >> 16) - (255 -texture->shadow))<<16)) | ft_max(0 ,((((c & 0x00FF00) >> 8) - (255 - texture->shadow)) << 8)) | ft_max(0,((c & 0x0000FF) - (255 - texture->shadow)));
				//img->data[y * width + x] = c;
			}
			x++;
		}
		y++;
	}
	return (ft_free_local(pos, size));
}
