/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:36 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 11:40:59 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	obj_in_front(char **map, t_pos curr_pos, char direction)
{
	if (direction == 's' && in_arr(map[curr_pos.y + 1][curr_pos.x], "0PEC"))
		return (0);
	if (direction == 'w' && in_arr(map[curr_pos.y - 1][curr_pos.x], "0PEC"))
		return (0);
	if (direction == 'a' && in_arr(map[curr_pos.y][curr_pos.x - 1], "0PEC"))
		return (0);
	if (direction == 'd' && in_arr(map[curr_pos.y][curr_pos.x + 1], "0PEC"))
		return (0);
	return (1);
}

void	find_path(char **map, t_pos exit, t_pos curr_pos, t_mapinfo *map_info)
{
	int		i;
	int		pos_directions;
	char	direction;
	t_pos	next_pos;

	if (exit.x == curr_pos.x && exit.y == curr_pos.y)
		map_info->path = 1;
	i = 0;
	pos_directions = 0;
	direction = 's';
	map[curr_pos.y][curr_pos.x] = '1';
	while (i++ < 4)
	{
		if (!obj_in_front(map, curr_pos, direction))
		{
			next_pos = update_curr_pos(curr_pos, direction);
			pos_directions++;
			map[next_pos.y][next_pos.x] = '1';
			find_path(map, exit, next_pos, map_info);
			map[next_pos.y][next_pos.x] = '0';
		}
		direction = update_direction(direction);
	}
}

void	find_paths_c(char **map, t_mapinfo *map_info, int *error_flag)
{
	char	**temp_map;
	t_pos	*current;
	t_pos	curr_pos;
	t_pos	collect_pos;

	current = map_info->collect_xy;
	while (current && *error_flag == 0)
	{
		curr_pos = init_pos(map_info->x_start, map_info->y_start);
		collect_pos = init_pos(current->x, current->y);
		map_info->path = 0;
		temp_map = cpy_map(map, *map_info);
		if (!temp_map)
		{
			*error_flag = 1;
			return ;
		}
		find_path(temp_map, collect_pos, curr_pos, map_info);
		free_map(&temp_map);
		if (map_info->path == 0)
			*error_flag = 13;
		current = current->next;
	}
}

void	check_path(char **map, t_mapinfo *map_info, int *error_flag)
{
	t_pos	exit;
	t_pos	curr_pos;
	char	**temp_map;

	exit = init_pos(map_info->x_exit, map_info->y_exit);
	curr_pos = init_pos(map_info->x_start, map_info->y_start);
	temp_map = cpy_map(map, *map_info);
	if (!temp_map)
	{
		*error_flag = 1;
		return ;
	}
	find_path(temp_map, exit, curr_pos, map_info);
	free_map(&temp_map);
	if (map_info->path == 0)
		*error_flag = 6;
	else
		find_paths_c(map, map_info, error_flag);
}
