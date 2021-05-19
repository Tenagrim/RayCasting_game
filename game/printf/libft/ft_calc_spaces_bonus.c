#include "libft.h"

void	calc_spaces(const char *str, size_t len, size_t *pref, size_t *post)
{
	size_t	i;

	i = 0;
	*post = 0;
	*pref = 0;
	while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	*pref = i;
	i = len - 1;
	while (i != 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i--;
	*post = len - i - 1;
}
