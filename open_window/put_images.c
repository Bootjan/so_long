/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:24 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_image_to_window(mlx_t *window, mlx_image_t *image, t_pos offset, int z)
{
	int	index;

	index = mlx_image_to_window(window, image, \
	offset.x * BLOCK_SIZE, offset.y * BLOCK_SIZE);
	if (index >= 0)
		mlx_set_instance_depth(&(image->instances[index]), z);
	return (index);
}

int	put_generic_images(mlx_t *window, t_images *images, \
t_pos offset, char element)
{
	int	error_flag;

	error_flag = 0;
	if (element == '0' || element == 'P' || element == 'C')
		error_flag = put_image_to_window(window, images->floor, offset, 1);
	if (element == '1' && error_flag != -1)
		error_flag = put_image_to_window(window, images->wall, offset, 1);
	if (element == 'E' && error_flag != -1)
		error_flag = put_image_to_window(window, images->exit, offset, 1);
	if (element == 'E' && error_flag != -1)
		error_flag = put_image_to_window(window, images->o_exit, offset, 0);
	if (element == 'P' && error_flag != -1)
		error_flag = put_image_to_window(window, images->front, offset, 3);
	return (error_flag);
}

int	put_coins_to_window(mlx_t *window, mlx_image_t *collect, \
t_pos offset, t_collect **coins_info)
{
	int	index;

	index = put_image_to_window(window, collect, offset, 2);
	if (index == -1)
	{
		free_coins_list(coins_info);
		return (0);
	}
	if (!coinlist_push_back(coins_info, index, offset.x, offset.y))
	{
		free_coins_list(coins_info);
		return (0);
	}
	return (1);
}

t_collect	*put_images_to_window(mlx_t *window, t_images *images, \
char **map, t_mapinfo map_info)
{
	int			i;
	char		element;
	t_pos		offset;
	t_collect	*coins_info;
	int			error_flag;

	i = 0;
	coins_info = NULL;
	error_flag = 0;
	while (i < map_info.height * map_info.width && error_flag != -1)
	{
		offset.x = i % map_info.width;
		offset.y = i / map_info.width;
		element = map[offset.y][offset.x];
		error_flag = put_generic_images(window, images, offset, element);
		if (element == 'C' && error_flag != -1)
			if (!put_coins_to_window(window, images->collect, \
			offset, &coins_info))
				return (NULL);
		i++;
	}
	if (error_flag == -1)
		free_coins_list(&coins_info);
	return (coins_info);
}
