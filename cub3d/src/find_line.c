/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:06 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:19:14 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char		*find_line(t_list *file, char *key)
{
	t_list	*p;
	char	*res;
	char	*susp;

	p = file;
	res = NULL;
	while (p)
	{
		susp = (char *)(p->content);
		if (!ft_strncmp(susp, key, ft_strlen(key)))
			return (susp);
		p = p->next;
	}
	return (res);
}
