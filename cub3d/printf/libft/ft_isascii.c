#include "libft.h"

int	ft_isascii(int c)
{
	int res;

	res = c >= 0x0 && c <= 0x7f;
	return (res);
}
