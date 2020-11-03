/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:27:45 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 12:51:16 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char		*get_str(char c)
{
	char	*res;

	res = ft_stralloc(1);
	res[0] = c;
	return (res);
}

int				ft_ifchar(t_attr *attr, va_list arg)
{
	char	*str;
	int		len;
	char	tmp;

	tmp = (char)va_arg(arg, int);
	str = get_str(tmp);
	len = ft_format_output_str(attr, str);
	free(str);
	return (len);
}
