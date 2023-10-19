/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:36 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/19 20:37:42 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	update_direction(char direction)
{
	if (direction == 's')
		return ('a');
	if (direction == 'a')
		return ('w');
	if (direction == 'w')
		return ('d');
	return ('s');
}

t_pos	update_curr_pos(t_pos curr_pos, char direction)
{
	t_pos	new_pos;

	if (direction == 's')
		new_pos = init_pos(curr_pos.x, curr_pos.y + 1);
	if (direction == 'w')
		new_pos = init_pos(curr_pos.x, curr_pos.y - 1);
	if (direction == 'a')
		new_pos = init_pos(curr_pos.x - 1, curr_pos.y);
	if (direction == 'd')
		new_pos = init_pos(curr_pos.x + 1, curr_pos.y);
	return (new_pos);
}

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
		
	if (exit.x == curr_pos.x && exit.y == curr_pos.y)
		map_info->path = 1;
	i = 0;
	pos_directions = 0;
	direction = 's';
	while (i++ < 4)
	{
		if (!obj_in_front(map, curr_pos, direction))
		{
			curr_pos = update_curr_pos(curr_pos, direction);
			pos_directions++;
			map[curr_pos.y][curr_pos.x] = '1';
			find_path(map, exit, curr_pos, map_info);
			map[curr_pos.y][curr_pos.x] = '0';
		}
		direction = update_direction(direction);
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
}
