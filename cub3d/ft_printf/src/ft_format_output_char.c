/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_output_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:25:31 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 12:56:30 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_format_output_char(t_attr *attr, char *str)
{
	if (!attr)
		return (1);
	ft_putstr(str);
	return (1);
}
