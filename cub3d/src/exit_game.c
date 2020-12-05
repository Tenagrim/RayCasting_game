/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:07:33 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 21:34:17 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	exit_game(t_game *game, int code)
{
	if (code < 0)
		ft_printf("Error\n");
	ft_printf("Exiting with code: %d\n", code);
	if (game)
	{
		mlx_do_key_autorepeaton(game->mlx->mlx_ptr);
		clear_game(&game);
	}
	exit(code);
	return (code);
}
