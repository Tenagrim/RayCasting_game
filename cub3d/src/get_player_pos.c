/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:00 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:38:01 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		get_pl_pos(t_game *game, char c, int i, int j)
{
	if (c && ft_strchr(MAP_DIRS_CHARS, c))
	{
		if (game->settings->parse_finds & PARSE_PL_POS_FOUND)
		{
			ft_printf("exit -1\n");
			return (-1);
		}
		game->settings->parse_finds |= PARSE_PL_POS_FOUND;
		if (c == 'N')
			game->player->angle = M_PI * 2 - M_PI / 2;
		else if (c == 'E')
			game->player->angle = 0.0;
		else if (c == 'S')
			game->player->angle = M_PI / 2;
		else if (c == 'W')
			game->player->angle = M_PI;
		game->player->pos->x = j * game->settings->sq_size +
			game->settings->sq_size / 2 + 1;
		game->player->pos->y = i * game->settings->sq_size +
			game->settings->sq_size / 2 + 1;
	}
	return (0);
}

int				get_player_pos(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map->map_size->y)
	{
		j = 0;
		while (j < game->map->map_size->x)
		{
			c = game->map->map[i][j];
			if ((get_pl_pos(game, c, i, j)) == -1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
