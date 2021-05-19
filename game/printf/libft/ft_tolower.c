#include "libft.h"

static int	ft_is_upper(int c)
{
	int res;

	res = c >= 'A' && c <= 'Z';
	return (res);
}

int			ft_tolower(int c)
{
	return (ft_is_upper(c) ? c + 32 : c);
}
