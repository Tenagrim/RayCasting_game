#include "libft.h"

int	ft_islower(int c)
{
	int res;

	res = c >= 'a' && c <= 'z';
	return (res);
}
