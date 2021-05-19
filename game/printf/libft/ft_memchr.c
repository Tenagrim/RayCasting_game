#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = (unsigned char *)str;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == val)
			return (p + i);
		i++;
	}
	return (NULL);
}
