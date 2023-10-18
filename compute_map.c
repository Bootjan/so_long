/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:56:43 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/18 20:27:04 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lines	*compute_lines(int fd, t_mapinfo *map_info, int *error_flag)
{
	char	*line;
	t_lines	*lines;

	map_info->width = -1;
	lines = NULL;
	while (1)
	{
		line = line_without_nl(fd);
		if (!line)
			break ;
		map_info->width = compute_map_width(map_info->width, line);
		if (map_info->width == -1)
		{
			*error_flag = 2;
			free_list(&lines, *error_flag);
		}
		else
			ft_lpush_back(&lines, line, error_flag);
		if (*error_flag != 0)
			return (NULL);
		(map_info->height)++;
	}
	return (lines);
}

char	**fill_map(t_lines **lines, int lines_n, int *error_flag)
{
	char	**map;
	int		i;

	map = ft_calloc(lines_n + 1, SIZE_OF_CHAR_PTR);
	if (!map)
	{
		*error_flag = 1;
		free_list(lines, *error_flag);
		return (NULL);
	}
	i = 0;
	while (i < lines_n)
	{
		map[i] = put_line_map(*lines, i);
		i++;
	}
	free_list(lines, 0);
	return (map);
}

char	**compute_map(int fd, t_mapinfo *map_info, int *error_flag)
{
	char	**map;
	t_lines	*lines;

	lines = compute_lines(fd, map_info, error_flag);
	if (!lines)
		return (NULL);
	if (map_info->height < 3 || map_info->width < 3)
	{
		*error_flag = 2;
		free_list(&lines, *error_flag);
		return (NULL);
	}
	map = fill_map(&lines, map_info->height, error_flag);
	if (!map)
		return (NULL);
	if (!check_validity_map(map, map_info, error_flag))
		free_map(&map);
	return (map);
}

void	print_map(char **map, t_mapinfo map_info)
{
	int	i;

	i = 0;
	while (i < map_info.height)
		ft_putendl_fd(map[i++], 1);
}

char	**load_map(t_mapinfo *map_info, int *error_flag)
{
	char	**map;
	int		fd;

	fd = open("map.txt", O_RDONLY); // check fd
	init_map_info(map_info);
	map = compute_map(fd, map_info, error_flag);
	close(fd);
	return (map);
}
