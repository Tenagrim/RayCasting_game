#include <cub3d.h>

t_list	*ft_read_file(char *filename)
{
	t_list	*file;
	t_list	*tmp;
	char	*line;
	int		fd;

	file = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_lstnew((void*)line);
		ft_lstadd_back(&file, tmp);
	}
	tmp = ft_lstnew((void*)line);
	ft_lstadd_back(&file, tmp);
	return (file);
}
