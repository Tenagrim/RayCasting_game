/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_intpair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:45 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:08:46 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_intpair	*ft_new_intpair(int x, int y)
{
	t_intpair	*res;

	res = malloc(sizeof(t_intpair));
	res->x = x;
	res->y = y;
	return (res);
}
