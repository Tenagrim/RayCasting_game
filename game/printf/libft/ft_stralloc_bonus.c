#include "libft.h"

char	*ft_stralloc(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	return (res);
}
