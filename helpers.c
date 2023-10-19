/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:41:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/19 21:08:10 by bschaafs         ###   ########.fr       */
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
	map_info->path = 0;
}

void	free_map(char ***map)
{
	int	i;

	if (!*map)
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		(*map)[i++] = NULL;
	}
	free(*map);
	*map = NULL;
}

int	compute_map_width(int current_width, char *line)
{
	if (!line)
		return (current_width);
	if (current_width == -1)
		return (ft_strlen(line));
	if (current_width != (int)ft_strlen(line))
		return (-1);
	return (current_width);
}

void	print_map(char **map, t_mapinfo map_info)
{
	int	i;

	i = 0;
	while (i < map_info.height)
		ft_putendl_fd(map[i++], 1);
}

void	check_elements(char **map, t_mapinfo map_info, int *error_flag)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if(!in_arr(map[y][x++], "01ECP"))
			{
				*error_flag = 7;
				return ;
			}
		}
		y++;
	}
}
