#include "libft.h"

int	ft_isprint(int c)
{
	int res;

	res = (c >= ' ' && c <= '~');
	return (res);
}
