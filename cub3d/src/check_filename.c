#include <cub3d.h>

int	check_filename(char *name)
{
	int len;

	if ((len = ft_strlen(name)) <= 4)
		return (0);
	if (ft_strcmp(name + (len - 4), ".cub"))
		return (0);
	return (1);
}
