#include <cub3d.h>

int	ft_clear_split(char ***splitted)
{
	char	**p;

	if (!splitted || !(*splitted))
		return (0);	
	p = *splitted;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(*splitted);
	*splitted = NULL;
	return (0);
}
