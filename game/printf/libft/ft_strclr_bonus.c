#include "libft.h"

void		ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
		*(s++) = '\0';
}
