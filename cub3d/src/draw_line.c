/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:45 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 20:23:13 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	init_l(t_intpair *d, t_intpair *s, t_intpair *start,
		t_intpair *stop)
{
	d->x = ft_abs(stop->x - start->x);
	d->y = -ft_abs(stop->y - start->y);
	s->x = (start->x < stop->x) ? 1 : -1;
	s->y = (start->y < stop->y) ? 1 : -1;
}

int			draw_line(t_game *game, t_intpair *start,
		t_intpair *stop, int color)
{
	t_intpair	d;
	t_intpair	s;
	t_intpair	err;

	crop(game, start, stop);
	init_l(&d, &s, start, stop);
	err.x = d.x + d.y;
	while (1)
	{
		draw_pixel(game, start->x, start->y, color);
		if (start->x == stop->x && start->y == stop->y)
			break ;
		err.y = 2 * err.x;
		if (err.y >= d.y)
		{
			err.x += d.y;
			start->x = start->x + s.x;
		}
		if (err.y <= d.x)
		{
			err.x += d.x;
			start->y = start->y + s.y;
		}
	}
	return (ft_free_local(start, stop));
}
