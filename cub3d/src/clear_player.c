/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:22 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 20:00:11 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		clear_player(t_game *game)
{
	if (!(game->player))
		return ;
	if (game->player->pos)
		free(game->player->pos);
	free(game->player);
	game->player = NULL;
}
