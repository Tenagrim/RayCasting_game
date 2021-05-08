#include "libft.h"

void	ft_strappend(char **str, char *append)
{
	char *res;

	if (!*str)
	{
		*str = ft_strdup(append);
		return ;
	}
	res = ft_strjoin(*str, append);
	if (*str)
		free(*str);
	*str = res;
}
