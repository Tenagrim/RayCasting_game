#include <ft_printf.h>

char	ft_get_conv(char **format)
{
	char	res;

	res = 0;
	if (ft_strchr(CONVERSIONS, **format))
		res = **format;
	return (res);
}
