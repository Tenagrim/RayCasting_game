#include <cub3d.h>

t_settings *ft_default_settings(void)
{
	t_settings *res;
	
	res = (t_settings*)malloc(sizeof(t_settings));
	res->fov = M_PI / 3;
	res->win_size = ft_new_intpair(800, 600);
	res->numrays = 30;
	res->sq_size = 20;
	res->depth = 30.0;	
	return (res);
}
