/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:13:57 by gshona            #+#    #+#             */
/*   Updated: 2020/12/07 12:16:12 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		screenshot(t_game *game)
{
	draw_floor(game);
	draw_ceil(game);
	raycast_im(game);
	draw_sprites(game);
	save_bmp(game);
	clear_game(&game);
	ft_printf("Screenshot saved\n");
	return (0);
}
