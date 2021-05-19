#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	val = (unsigned char)value;
	p = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = val;
		i++;
	}
	return (ptr);
}
