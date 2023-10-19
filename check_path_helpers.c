/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:17:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/19 13:35:04 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
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
