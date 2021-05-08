#include "libft.h"

int	ft_isupper(int c)
{
	int res;

	res = c >= 'A' && c <= 'Z';
	return (res);
}
