/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:41:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/31 18:11:10 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map_info(t_mapinfo *map_info)
{
	map_info->width = 0;
	map_info->height = 0;
	map_info->x_exit = 0;
	map_info->y_exit = 0;
	map_info->collectables_n = 0;
	map_info->path = 0;
	map_info->poss_collect = 0;
	map_info->collect_xy = NULL;
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
	if (*map)
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
			if (!in_arr(map[y][x++], "01ECP"))
			{
				*error_flag = 7;
				return ;
			}
		}
		y++;
	}
}

void	push_collect_xy(t_mapinfo *map_info, int x, int y, int *error_flag)
{
	t_pos	*element;
	t_pos	*current;

	element = ft_calloc(1, sizeof(t_pos));
	if (!element)
	{
		*error_flag = 1;
		return ;
	}
	element->x = x;
	element->y = y;
	element->next = NULL;
	current = map_info->collect_xy;
	if (!current)
	{
		map_info->collect_xy = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}
