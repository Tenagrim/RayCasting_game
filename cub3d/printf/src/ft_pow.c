#include <ft_printf.h>

int	ft_pow(int val, int pow)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i++ < pow)
		res *= val;
	return (res);
}
