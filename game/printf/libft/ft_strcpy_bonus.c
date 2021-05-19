#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	ft_memcpy((void *)dest, (const void *)src, len);
	dest[len] = 0;
	return (dest);
}
