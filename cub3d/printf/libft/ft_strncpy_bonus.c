#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (n > len)
	{
		ft_memcpy((void *)dest, (const void *)src, len);
		i = len;
		while (i < n)
			dest[i++] = 0;
	}
	else
		ft_memcpy((void *)dest, (const void *)src, n);
	return (dest);
}
