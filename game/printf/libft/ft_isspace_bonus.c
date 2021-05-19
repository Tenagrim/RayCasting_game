#include "libft.h"

int	ft_isspace(int c)
{
	int res;

	res = c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r';
	return (res);
}
