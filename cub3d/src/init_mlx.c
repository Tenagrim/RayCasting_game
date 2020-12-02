#include <cub3d.h>

t_mlx	*init_mlx(void)
{
	t_mlx	*res;

	if (!(res = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	res->win = NULL;
	res->mlx_ptr = NULL;
	res->img = NULL;
	return (res);
}
