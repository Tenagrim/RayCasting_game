#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char*)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	while (i < size)
		res[i++] = 0;
	return (res);
}
