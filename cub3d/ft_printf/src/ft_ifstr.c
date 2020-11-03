/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:29:23 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 16:40:36 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_ifstr(t_attr *attr, va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (!str)
	{
		//str = (attr->precision == -1 || attr->precision >= 6) ?
		str = ft_strdup("(null)"); //: ft_strdup("");
		len = ft_format_output_str(attr, str);
		free(str);
		return (len);
	}
	len = ft_format_output_str(attr, str);
	return (len);
}
