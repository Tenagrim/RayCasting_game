/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:01:48 by gshona            #+#    #+#             */
/*   Updated: 2020/11/03 13:59:34 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
/*
static void	print_elem(void *p)
{
	ft_putstr((char*)p);
	
	ft_putchar('\n');
}
*/
void		ft_print_file(t_list *file)
{
	//ft_lstiter(file, print_elem);
	t_list *p;

	p = file;
	while (p)
	{
		ft_putendl_fd((char*)(p->content), 1);
		p = p->next;
	}
}
