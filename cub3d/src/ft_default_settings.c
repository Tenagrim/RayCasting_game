/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:26 by gshona            #+#    #+#             */
/*   Updated: 2020/12/07 10:43:03 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_settings	*ft_default_settings(void)
{
	t_settings *res;

	res = (t_settings*)malloc(sizeof(t_settings));
	res->fov = M_PI / 4;
	res->h_fov = M_PI / 8;
	res->win_size = ft_new_intpair(800, 600);
	res->win_max = ft_new_intpair(2560, 1440);
	res->numrays = 300;
	res->z_buffer = (float*)malloc(sizeof(float) * res->numrays);
	res->delta_angle = res->fov / res->numrays;
	res->sq_size = 64;
	res->dist = res->numrays / (2 * tan(res->h_fov));
	res->scale = (float)res->win_size->x / (float)res->numrays;
	res->texture_size = ft_new_intpair(64, 64);
	res->texture_scale = res->texture_size->x / (float)res->sq_size;
	res->proj_coeff = res->sq_size * 1000;
	res->floor_color = 0xA1002C;
	res->ceil_color = 0x00002C;
	res->settings = 0;
	res->parse_finds = 0;
	res->shadow_mult = 0.000027;
	res->body = res->sq_size / 6.;
	res->proj_mult = 1.5;
	return (res);
}

/*
**res->proj_coeff = res->dist * res->sq_size;
*/
