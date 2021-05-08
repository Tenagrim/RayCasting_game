#include <ft_printf.h>

int				ft_ifchar(t_attr *attr, va_list arg)
{
	int		len;
	char	tmp;

	tmp = (char)va_arg(arg, int);
	len = ft_format_output_char(attr, tmp);
	return (len);
}
