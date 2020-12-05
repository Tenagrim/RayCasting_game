/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:04:03 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:59:53 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_filename(char *name)
{
	int len;

	if ((len = ft_strlen(name)) <= 4)
		return (0);
	if (ft_strcmp(name + (len - 4), ".cub"))
		return (0);
	return (1);
}
