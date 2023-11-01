/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:17:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/31 17:18:51 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.next = NULL;
	return (pos);
}

int	in_arr(char s, char *arr)
{
	int	len;

	len = ft_strlen(arr);
	while (len-- > 0)
		if (arr[len] == s)
			return (1);
	return (0);
}

char	**cpy_map(char **map, t_mapinfo map_info)
{
	char	**temp_map;
	int		i;

	temp_map = ft_calloc(map_info.height + 1, SIZE_OF_CHAR_PTR);
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < map_info.height)
	{
		temp_map[i] = ft_strdup(map[i]);
		if (!temp_map[i])
		{
			free_map(&temp_map);
			return (NULL);
		}
		i++;
	}
	return (temp_map);
}
