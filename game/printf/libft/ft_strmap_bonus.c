#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	res = ft_stralloc(len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
