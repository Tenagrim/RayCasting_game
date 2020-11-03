#include <cub3d.h>

t_floatpair		*ft_new_floatpair(float	x, float y)
{
	t_floatpair *res;

	res = (t_floatpair*)malloc(sizeof(t_floatpair));
	res->x = x;
	res->y = y;
	return (res);
}
