/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:38 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:11:56 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	*load_texture(t_game *game, char *filename)
{
	t_img	*img;
	t_mlx	*mlx;

	mlx = game->mlx;
	img = (t_img*)malloc(sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, filename, &(img->width),
			&(img->height));
	if (!(img->img_ptr))
	{
		free(img);
		exit_game(game, -3);
	}
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp),
			&(img->size_l), &(img->endian));
	return (img);
}
