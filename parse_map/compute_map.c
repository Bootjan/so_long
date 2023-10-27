/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:56:43 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:45:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_lines	*compute_lines(int fd, t_mapinfo *map_info, int *error_flag)
{
	char	*line;
	t_lines	*lines;

	map_info->width = -1;
	lines = NULL;
	while (*error_flag == 0)
	{
		line = line_without_nl(fd, error_flag);
		map_info->width = compute_map_width(map_info->width, line);
		if (*error_flag != 0 || map_info->width == -1)
		{
			if (map_info->width == -1)
				*error_flag = 10;
			if (line)
				free(line);
			return (lines);
		}
		if (!line)
			break ;
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

int	check_validity_map(char **map, t_mapinfo *map_info, int *error_flag)
{
	check_exits(map, map_info, error_flag);
	check_start(map, map_info, error_flag);
	check_collectables(map, map_info, error_flag);
	check_left_right(map, *map_info, error_flag);
	check_top_and_bottem(map, *map_info, error_flag);
	check_elements(map, *map_info, error_flag);
	if (*error_flag != 0)
		return (0);
	check_path(map, map_info, error_flag);
	if (*error_flag != 0)
		return (0);
	return (1);
}

char	**compute_map(int fd, t_mapinfo *map_info, int *error_flag)
{
	char	**map;
	t_lines	*lines;

	lines = compute_lines(fd, map_info, error_flag);
	if (*error_flag != 0 || !lines)
	{
		free_list(&lines, 1);
		return (NULL);
	}
	if (map_info->height < 3 || map_info->width < 3)
	{
		*error_flag = 12;
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

char	**load_map(char *file, t_mapinfo *map_info, int *error_flag)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || fd > MAX_FD)
	{
		*error_flag = 9;
		return (NULL);
	}
	init_map_info(map_info);
	map = compute_map(fd, map_info, error_flag);
	close(fd);
	return (map);
}
