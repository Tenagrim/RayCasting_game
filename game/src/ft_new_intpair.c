#include <cub3d.h>

t_intpair	*ft_new_intpair(int x, int y)
{
	t_intpair	*res;

	res = malloc(sizeof(t_intpair));
	res->x = x;
	res->y = y;
	return (res);
}
