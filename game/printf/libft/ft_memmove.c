#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*p_d;
	unsigned char	*p_s;
	size_t			i;
	int				len;

	if (!src && !dest)
		return (NULL);
	p_s = (unsigned char *)src;
	p_d = (unsigned char *)dest;
	i = -1;
	len = (int)num;
	if (p_s < p_d)
	{
		while (--len >= 0)
			p_d[len] = p_s[len];
	}
	else
	{
		while (++i < num)
			p_d[i] = p_s[i];
	}
	return (p_d);
}
