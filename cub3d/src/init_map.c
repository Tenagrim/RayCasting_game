#include <cub3d.h>

t_map		*init_map(void)
{
	t_map	*res;
	int	i;

	if (!(res = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	res->map = NULL;
	res->sprites = NULL;
	if (!(res->texture_paths = (char**)malloc(sizeof(char*) * 5)))
		return ((t_map*)clear_map(&res));
	i = 0;
	while (i++ < 5)
		res->texture_paths[i - 1] = NULL;
	if (!(res->textures = (t_img**)malloc(sizeof(t_img*) * 5)))
		return ((t_map*)clear_map(&res));
	i = 0;
	while (i++ < 5)
		res->textures[i - 1] = NULL;
	if (!(res->map_size = ft_new_intpair(0, 0)))
		return (NULL);
	return (res);
}
