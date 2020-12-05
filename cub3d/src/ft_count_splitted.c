/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_splitted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:22 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:08:24 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_count_splitted(char **splitted)
{
	int	count;

	count = 0;
	while (splitted[count])
		count++;
	return (count);
}
