#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	char		value;

	value = (char)c;
	i = (int)ft_strlen(str);
	if (i == 0 && c == '\0')
		return ((char*)str);
	if (i == 0)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == value)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
