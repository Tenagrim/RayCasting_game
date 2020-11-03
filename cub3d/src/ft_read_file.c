/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:02:08 by gshona            #+#    #+#             */
/*   Updated: 2020/11/03 13:59:18 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_list	*ft_read_file(char *filename)
{
	t_list	*file;
	char	*line;
	t_list	*tmp;
	int	fd;

	file = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while(get_next_line(fd, &line) == 1)
	{
		tmp = ft_lstnew((void*)line);
		ft_lstadd_back(&file, tmp);
	}
	return (file);
}
