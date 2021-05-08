#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
