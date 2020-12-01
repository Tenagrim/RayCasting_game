#include <cub3d.h>

t_sprite	*ft_sprtnew(t_floatpair *pos)
{
	t_sprite	*res;

	res = (t_sprite *)malloc(sizeof(t_sprite));
	res->next = NULL;
	res->sorted = NULL;
	res->dist = 0.0;
	res->pos = pos;
	return (res);
}
