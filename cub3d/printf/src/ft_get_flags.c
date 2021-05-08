#include <ft_printf.h>

int	ft_get_flags(char **format)
{
	int res;

	res = 0;
	while (ft_strchr(FLAGS, **format))
	{
		if (**format == '+')
			res = res | FLAG_PLUS;
		else if (**format == '-')
			res = res | FLAG_MINUS;
		else if (**format == '#')
			res = res | FLAG_SHARP;
		else if (**format == '0')
			res = res | FLAG_ZERO;
		else if (**format == ' ')
			res = res | FLAG_SPACE;
		*format = *format + 1;
	}
	return (res);
}
