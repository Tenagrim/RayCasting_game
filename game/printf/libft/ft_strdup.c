#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
