#include "libft.h"

void		ft_putstr(char const *str)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
}
