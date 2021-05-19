#include "libft.h"

size_t	ft_count_words(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	if (!str || !(str[0]))
		return (0);
	i = 1;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i - 1] != sep)
			count++;
		i++;
	}
	if (str[i - 1] != sep)
		count++;
	return (count);
}
