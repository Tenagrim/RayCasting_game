/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_output_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:25:38 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 17:09:33 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void			print_spaces(int count, char c)
{
	int i;

	if (count <= 0)
		return ;
	i = 0;
	while (i++ < count)
		write(1, &c, 1);
}

static int			print_num(t_attr *attr, char *str, int zeros, int lenn)
{
	int	len;

	len = 0;
	if (!lenn)
		return (0);
	if (attr->flags & FLAG_PLUS)
	{
		ft_putchar('+');
		len++;
	}
	print_spaces(zeros, '0');
	ft_putstr(str);
	return (len);
}

static void			minus(char **str)
{
	if (**str == '-')
	{
		write(1, "-", 1);
		*str = *str + 1;
	}
}

static void			init(t_attr *attr, int *len, char *space, char *str)
{
	*len = (attr->precision) ? (int)ft_strlen(str) : 0;
	*space = (attr->flags & FLAG_ZERO && !(attr->flags & FLAG_MINUS) && attr->precision == -1) ? '0' : ' ';
}

int					ft_format_output_digit(t_attr *attr, char *str)
{
	int		spaces;
	int		len;
	int		zeros;
	char	space;

	init(attr, &len, &space, str);
	zeros = (attr->precision <= 0) ? 0 : ft_max(attr->precision, len) - len;
	zeros = (*str == '-' && zeros) ? zeros + 1 : zeros;
	spaces = (attr->width != -1) ? attr->width - len - zeros : 0;
	spaces = (attr->flags & FLAG_PLUS) ? spaces - 1 : spaces;
	if (space == '0')
		minus(&str);
	if (attr->flags & FLAG_MINUS)
	{
		minus(&str);
		print_num(attr, str, zeros, len);
		print_spaces(spaces, space);
	}
	else
	{
		print_spaces(spaces, space);
		minus(&str);
		print_num(attr, str, zeros, len);
	}
	return (len + spaces + zeros);
}
