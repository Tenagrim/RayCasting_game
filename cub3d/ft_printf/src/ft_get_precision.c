/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:26:33 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 12:45:19 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		support(char **format, int *len, char *start)
{
	while (ft_isdigit(**format))
		*format = *format + 1;
	*len = format[0] - start;
}

int				ft_get_precision(char **format, va_list arg)
{
	int		res;
	char	*start;
	char	*digit;
	int		len;

	if (**format == '.')
		*format = *format + 1;
	else
		return (-1);
	if (**format == '*')
	{
		*format = *format + 1;
		return (va_arg(arg, int));
	}
	start = *format;
	support(format, &len, start);
	if (len == 0)
		return (0);
	else
	{
		digit = ft_strsub(start, 0, len);
		res = ft_atoi(digit);
		free(digit);
		return (res);
	}
}
