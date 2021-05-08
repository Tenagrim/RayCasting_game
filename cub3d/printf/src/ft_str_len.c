#include <ft_printf.h>

size_t		ft_str_len(char *str)
{
	size_t	res;

	res = 0;
	while (*str)
	{
		if (*str != '-')
			res++;
		str += 1;
	}
	return (res);
}
