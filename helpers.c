/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:41:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/18 20:26:44 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_info(t_mapinfo *map_info)
{
	map_info->width = 0;
	map_info->height = 0;
	map_info->x_exit = 0;
	map_info->y_exit = 0;
	map_info->collectables_n = 0;
}

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

int	compute_map_width(int current_width, char *line)
{
	if (current_width == -1)
		return (ft_strlen(line));
	if (current_width != (int)ft_strlen(line))
		return (-1);
	return (current_width);
}

char	*line_without_nl(int fd)
{
	int		len;
	char	*str;
	char	*out;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] != '\n')
		return (str);
	out = ft_substr(str, 0, len - 1);
	free(str);
	if (!out)
		return (NULL);
	return (out);
}

int	check_validity_map(char **map, t_mapinfo *map_info, int *error_flag)
{
	check_top_and_bottem(map, *map_info, error_flag);
	check_left_right(map, *map_info, error_flag);
	check_exits(map, map_info, error_flag);
	check_start(map, map_info, error_flag);
	check_collectables(map, map_info, error_flag);
	if (*error_flag == 2)
		return (0);
	return (1);
}
