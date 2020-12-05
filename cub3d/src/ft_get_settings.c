/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:36 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:08:38 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_get_settings(t_game *game)
{
	t_settings *res;

	res = game->settings;
	if (res->win_size->x < res->numrays)
	{
		res->numrays = res->win_size->x;
		free(res->z_buffer);
		res->z_buffer = (float*)malloc(sizeof(float) * res->numrays);
		res->delta_angle = res->fov / res->numrays;
		res->dist = res->numrays / (2 * tan(res->h_fov));
		res->proj_coeff = res->dist * res->sq_size;
	}
	res->scale = (float)res->win_size->x / (float)res->numrays;
}
