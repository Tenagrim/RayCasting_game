/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprtadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:10:44 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:10:45 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_sprtadd_front(t_sprite **list, t_sprite *new)
{
	if (*list)
	{
		new->next = *list;
		*list = new;
	}
	else
		*list = new;
}
