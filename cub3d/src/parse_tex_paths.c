/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:12:58 by gshona            #+#    #+#             */
/*   Updated: 2020/12/05 19:40:27 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		map_get_tex_ind(char *dir)
{
	if (!ft_strcmp(dir, "NO "))
		return (0);
	else if (!ft_strcmp(dir, "WE "))
		return (1);
	else if (!ft_strcmp(dir, "SO "))
		return (2);
	else if (!ft_strcmp(dir, "EA "))
		return (3);
	else if (!ft_strcmp(dir, "S "))
		return (4);
	return (-1);
}

static int		get_tex_path(t_game *game, t_list *file, char *dir)
{
	int		ind;
	char	*line;

	line = find_line(file, dir);
	ind = map_get_tex_ind(dir);
	if (game->settings->parse_finds & 1 << (ind + 1) || !line)
		return (0);
	game->settings->parse_finds |= 1 << (ind + 1);
	game->map->texture_paths[ind] = ft_strdup(line + ft_strlen(dir));
	return (1);
}

int				parse_tex_paths(t_game *game, t_list *file)
{
	if (get_tex_path(game, file, "NO ") &&
			get_tex_path(game, file, "WE ") &&
			get_tex_path(game, file, "SO ") &&
			get_tex_path(game, file, "EA ") &&
			get_tex_path(game, file, "S "))
		return (1);
	return (0);
}
