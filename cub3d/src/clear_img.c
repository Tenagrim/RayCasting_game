/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:05:09 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:05:12 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		clear_img(t_game *game, t_img **img)
{
	if (*img)
	{
		mlx_destroy_image(game->mlx->mlx_ptr, (*img)->img_ptr);
		free(*img);
		*img = NULL;
	}
}
