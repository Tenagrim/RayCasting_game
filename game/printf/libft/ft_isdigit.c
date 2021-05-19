#include "libft.h"

int	ft_isdigit(int c)
{
	int res;

	res = c >= '0' && c <= '9';
	return (res);
}
