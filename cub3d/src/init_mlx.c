/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:08 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:11:11 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx	*init_mlx(void)
{
	t_mlx	*res;

	if (!(res = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	res->win = NULL;
	res->mlx_ptr = NULL;
	res->img = NULL;
	return (res);
}
