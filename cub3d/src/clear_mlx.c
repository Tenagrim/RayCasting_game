/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:20 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:05:21 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clear_mlx(t_game *game)
{
	if (!(game->mlx))
		return ;
	if (game->mlx->img)
		clear_img(game, &(game->mlx->img));
	if (game->mlx->mlx_ptr && game->mlx->win)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win);
	free(game->mlx);
	game->mlx = NULL;
}
