#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	if (num == 0)
		return (0);
	i = 0;
	while (i < num - 1 && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (str1[i] < 0)
		return ((int)str2[i] - (int)str1[i]);
	else
		return ((int)str1[i] - (int)str2[i]);
}
