/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:59:19 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:59:24 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clear_game(t_game **game)
{
	if (*game)
	{
		clear_textures(*game);
		clear_map(&((*game)->map));
		clear_settings(*game);
		clear_player(*game);
		clear_mlx(*game);
		free(*game);
		*game = NULL;
	}
}
