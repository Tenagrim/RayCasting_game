#include <cub3d.h>

int	ft_count_splitted(char **splitted)
{
	int	count;

	count = 0;
	while (splitted[count])
		count++;
	return (count);
}
