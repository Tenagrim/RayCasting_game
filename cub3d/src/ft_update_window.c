/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:10:55 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:56:36 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_window(t_game *game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
}
