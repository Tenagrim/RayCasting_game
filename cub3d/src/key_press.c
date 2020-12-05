/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:12 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:18:29 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
** ft_printf("key pressed  code: %d\n", keycode);
*/

int	key_press(int keycode, t_game *game)
{
	if (keycode < 0 || !game)
		return (0);
	if (keycode == KEYS_W)
		game->player->move_flags |= MOVE_FLAG_FORW;
	else if (keycode == KEYS_S)
		game->player->move_flags |= MOVE_FLAG_BACK;
	else if (keycode == KEYS_A)
		game->player->move_flags |= MOVE_FLAG_LEFT;
	else if (keycode == KEYS_D)
		game->player->move_flags |= MOVE_FLAG_RIGHT;
	else if (keycode == KEYS_L_ARROW)
		game->player->move_flags |= MOVE_FLAG_ROT_L;
	else if (keycode == KEYS_R_ARROW)
		game->player->move_flags |= MOVE_FLAG_ROT_R;
	else if (keycode == KEYS_L_SHIFT)
		game->player->move_speed = game->player->run_speed;
	else if (keycode == KEYS_P)
		game->settings->settings ^= SETT_SHADOWS_ON;
	else if (keycode == KEYS_M)
		game->settings->settings ^= SETT_MAP_ON;
	else if (keycode == KEYS_C)
		game->settings->settings ^= SETT_COLL_ON;
	return (0);
}
