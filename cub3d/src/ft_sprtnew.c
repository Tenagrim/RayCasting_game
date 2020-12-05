/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprtnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:10:47 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:10:51 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_sprite	*ft_sprtnew(t_floatpair *pos)
{
	t_sprite	*res;

	res = (t_sprite *)malloc(sizeof(t_sprite));
	res->next = NULL;
	res->sorted = NULL;
	res->dist = 0.0;
	res->pos = pos;
	return (res);
}
