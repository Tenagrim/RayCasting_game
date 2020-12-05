/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sptradd_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:10:52 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:10:54 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_sprite	*ft_sprtadd_sorted(t_sprite **sorted, t_sprite *sprite)
{
	t_sprite	*p;
	t_sprite	*prev;

	if (!*sorted)
		return ((*sorted = sprite));
	p = *sorted;
	prev = NULL;
	while (*sorted && sprite->dist < (*sorted)->dist)
	{
		prev = *sorted;
		*sorted = (*sorted)->sorted;
	}
	if (!prev)
	{
		sprite->sorted = *sorted;
		*sorted = sprite;
	}
	else
	{
		sprite->sorted = prev->sorted;
		prev->sorted = sprite;
		*sorted = p;
	}
	return (sprite);
}
