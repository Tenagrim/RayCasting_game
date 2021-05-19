#include "libft.h"

static int	ft_is_lower(int c)
{
	int res;

	res = c >= 'a' && c <= 'z';
	return (res);
}

int			ft_toupper(int c)
{
	return (ft_is_lower(c) ? c - 32 : c);
}
