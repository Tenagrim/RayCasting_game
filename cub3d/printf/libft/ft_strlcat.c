#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	char	*res;

	if (!dest && !src)
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	res = dest;
	i = len_dest;
	if (n < len_dest + 1)
		return (len_src + n);
	while (i < n - 1 && src[i - len_dest] != '\0')
	{
		res[i] = src[i - len_dest];
		i++;
	}
	res[i] = '\0';
	return (len_dest + len_src);
}
