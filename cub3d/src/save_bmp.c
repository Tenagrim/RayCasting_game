#include <cub3d.h>

static void	write_int(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

static void	write_data(t_game *game, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = game->settings->win_size->x * (game->settings->win_size->y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < game->settings->win_size->x)
		{
			write_int(buffer, game->mlx->img->data[i]);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * game->settings->win_size->x;
	}
}

static void	write_header_p2(t_game *game, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	write_int(header + 4, game->settings->win_size->x);
	write_int(header + 8, game->settings->win_size->y);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

static void	write_header_p1(t_game *game, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = game->settings->win_size->x *
		game->settings->win_size->y * 4 + 54;
	header[10] = (unsigned char)(54);
	write_int(header + 2, n);
	write(fd, header, 14);
}

int			save_bmp(t_game *game)
{
	int		fd;

	fd = open("picture.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write_header_p1(game, fd);
	write_header_p2(game, fd);
	write_data(game, fd);
	close(fd);
	return (1);
}
