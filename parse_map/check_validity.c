/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:00 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/31 18:10:45 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_top_and_bottem(char **map, t_mapinfo map_info, int *error_flag)
{
	int	i;

	i = 0;
	while (i < map_info.width)
	{
		if (map[0][i++] != '1')
		{
			*error_flag = 5;
			return ;
		}
	}
	i = 0;
	while (i < map_info.width)
	{
		if (map[map_info.height - 1][i++] != '1')
		{
			*error_flag = 5;
			return ;
		}
	}
}

void	check_left_right(char **map, t_mapinfo map_info, int *error_flag)
{
	int	i;

	i = 1;
	while (i < map_info.height - 1)
	{
		if (map[i++][0] != '1')
		{
			*error_flag = 5;
			return ;
		}
	}
	i = 1;
	while (i < map_info.height - 1)
	{
		if (map[i++][map_info.width - 1] != '1')
		{
			*error_flag = 5;
			return ;
		}
	}
}

void	check_exits(char **map, t_mapinfo *map_info, int *error_flag)
{
	int	exit_n;
	int	x;
	int	y;

	exit_n = 0;
	y = 1;
	while (y < map_info->height - 1)
	{
		x = 1;
		while (x < map_info->width - 1)
		{
			if (map[y][x] == 'E')
			{
				map_info->x_exit = x;
				map_info->y_exit = y;
				exit_n++;
			}
			x++;
		}
		y++;
	}
	if (exit_n != 1)
		*error_flag = 3;
}

void	check_start(char **map, t_mapinfo *map_info, int *error_flag)
{
	int	start_n;
	int	x;
	int	y;

	start_n = 0;
	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (map[y][x] == 'P')
			{
				map_info->x_start = x;
				map_info->y_start = y;
				start_n++;
			}
			x++;
		}
		y++;
	}
	if (start_n != 1)
		*error_flag = 2;
}

void	check_collectables(char **map, t_mapinfo *map_info, int *error_flag)
{
	int	collect_n;
	int	x;
	int	y;

	collect_n = 0;
	y = 1;
	while (y < map_info->height - 1)
	{
		x = 1;
		while (x < map_info->width - 1)
		{
			if (map[y][x] == 'C')
			{
				map_info->collectables_n++;
				push_collect_xy(map_info, x, y, error_flag);
				collect_n++;
			}
			x++;
		}
		y++;
	}
	if (collect_n == 0)
		*error_flag = 4;
}
