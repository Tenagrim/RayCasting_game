#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(s + i);
		i++;
	}
}
