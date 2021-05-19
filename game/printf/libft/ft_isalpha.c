#include "libft.h"

int	ft_isalpha(int c)
{
	int res;

	res = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
	return (res);
}
