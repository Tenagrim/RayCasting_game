#include "libft.h"

size_t	ft_calc_digits(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
