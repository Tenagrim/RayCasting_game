/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:13:31 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:18:52 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	write_int(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

static int	write_header(t_game *game, int fd, int size)
{
	int						res;
	unsigned char			*header;

	if (!(header = ft_calloc(54, sizeof(unsigned char))))
		return (0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	write_int(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	write_int(header + 18, game->settings->win_size->x);
	write_int(header + 22, game->settings->win_size->y);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	res = write(fd, header, 54);
	free(header);
	return (!(res < 0));
}

static int	get_color(t_game *game, int x, int y)
{
	int	c;

	y = game->settings->win_size->y - y;
	c = game->mlx->img->data[y * game->settings->win_size->x + x];
	return (c);
}

static int	write_data(t_game *game, int fd, int pad)
{
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < game->settings->win_size->y)
	{
		j = 0;
		while (j < game->settings->win_size->x)
		{
			color = get_color(game, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, "\0\0\0", pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			save_bmp(t_game *game)
{
	int			size;
	int			fd;
	int			pad;
	int			res;

	pad = (4 - ((int)game->settings->win_size->x * 3) % 4) % 4;
	size = 54 + (3 * ((int)game->settings->win_size->x + pad) *
			(int)game->settings->win_size->y);
	if ((fd = open("picture.bmp", O_RDWR | O_TRUNC | O_CREAT, 0666)) < 0)
	{
		ft_printf("Error\nUnable to open file\n");
		return (0);
	}
	if (write_header(game, fd, size) && write_data(game, fd, pad))
		res = 1;
	else
		res = 0;
	close(fd);
	return (res);
}
