/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:17 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:08:19 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_clear_split(char ***splitted)
{
	char	**p;

	if (!splitted || !(*splitted))
		return (0);
	p = *splitted;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(*splitted);
	*splitted = NULL;
	return (0);
}
