/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:33 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:59:09 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		clear_sprites(t_sprite **sprites)
{
	t_sprite	*p;
	t_sprite	*p2;

	if (!(*sprites))
		return ;
	p = *sprites;
	while (p)
	{
		p2 = p;
		p = p->next;
		if (p2->pos)
			free(p2->pos);
		free(p2);
	}
	*sprites = NULL;
}
