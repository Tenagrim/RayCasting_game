#include <cub3d.h>

static char		**gen_map(void)
{
	char	**res;

	res = (char**)malloc(sizeof(char*) * 7);
	res[0] = ft_strdup("11111111111111111111111111111");
	res[2] = ft_strdup("10000000000000000000000000001");
	res[3] = ft_strdup("10000000000000000000000000001");
	res[4] = ft_strdup("10000000000000000000000000001");
	res[5] = ft_strdup("10000000000000000000000000001");
	res[6] = ft_strdup("11111111111111111111111111111");
	return (res);
}

t_map			*ft_get_map_from_file(t_list *file)
{
	t_map	*res;

	if (file) //FIXME
		return (NULL);
	res = (t_map *)malloc(sizeof(t_map));
	res->win_width = 800;
	res->win_height = 600;
	res->map = gen_map();
	res->map_size = ft_new_intpair(ft_strlen(res->map[0]), 7);
	return (res);
}
