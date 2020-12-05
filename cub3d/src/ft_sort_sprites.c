/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:10:38 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:32:30 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_sprite	*ft_sort_sprites(t_game *game, t_sprite *sprites)
{
	t_sprite	*sorted;
	t_floatpair	p;

	sorted = NULL;
	p.x = game->player->pos->x;
	p.y = game->player->pos->y;
	while (sprites)
	{
		sprites->dist =
			sqrt((((p.x - sprites->pos->x) * (p.x - sprites->pos->x) +
							(p.y - sprites->pos->y) *
							(p.y - sprites->pos->y))));
		sprites->sorted = NULL;
		ft_sprtadd_sorted(&sorted, sprites);
		sprites = sprites->next;
	}
	return (sorted);
}
