#include <cub3d.h>

int	error_map_line(int i, char *line, char dir)
{
	ft_printf("Error\n");
	ft_printf("Wrong map line:\n line: %d:\n%s\n", i, line);
	if (dir == 'v')
		ft_printf("verts\n");
	else
		ft_printf("horzs\n");
	return (0);
}
