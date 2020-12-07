/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:48 by gshona            #+#    #+#             */
/*   Updated: 2020/12/07 11:47:35 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_player	*ft_new_player(void)
{
	t_player *res;

	res = (t_player*)malloc(sizeof(t_player));
	res->pos = ft_new_floatpair(75.0, 130.0);
	res->walk_speed = 3.;
	res->run_speed = res->walk_speed * 2;
	res->move_speed = res->walk_speed;
	res->rot_speed = 0.044;
	res->angle = 0.0;
	res->move_flags = 0;
	return (res);
}
