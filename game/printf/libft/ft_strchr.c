#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t		i;
	size_t		len;
	char		value;

	value = (char)c;
	len = ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == value)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
