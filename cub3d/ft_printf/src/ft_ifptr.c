/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:29:12 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 16:23:10 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_ifptr(t_attr *attr, va_list arg)
{
	char			*str;
	char			*str2;
	int				len;
	void			*tmp;

	tmp = va_arg(arg, void*);
	if (!tmp)
	{
		str = ft_strdup("0x0");
		len = ft_format_output_str(attr, str);
		free(str);
		return (len);
	}
	str2 = ft_itoa_base_ul((unsigned long int)tmp, 16, 0);
	str = ft_strdup("0x");
	ft_strappend(&str, str2);
	free(str2);
	len = ft_format_output_digit(attr, str);
	free(str);
	return (len);
}
