/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:07:02 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:07:04 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_pixel(t_game *game, int x, int y, int color)
{
	t_img	*img;

	img = game->mlx->img;
	img->data[y * game->settings->win_size->x + x] = color;
}
