#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	p = malloc(nitems * size);
	if (p)
		ft_memset(p, 0, nitems * size);
	return (p);
}
