#include <cub3d.h>

t_settings *ft_default_settings(void)
{
	t_settings *res;

	res = (t_settings*)malloc(sizeof(t_floatpair));
	res->fov = M_PI / 3;
	
}
