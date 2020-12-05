/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_floatpair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:42 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:43:48 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_floatpair		*ft_new_floatpair(float x, float y)
{
	t_floatpair *res;

	res = (t_floatpair*)malloc(sizeof(t_floatpair));
	res->x = x;
	res->y = y;
	return (res);
}
