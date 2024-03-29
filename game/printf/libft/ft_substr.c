#include "libft.h"

char			*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(str);
	if (start >= len_s)
		return (ft_strdup(""));
	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	i = start;
	while (i < start + len && str[i] != '\0')
	{
		res[i - start] = str[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
