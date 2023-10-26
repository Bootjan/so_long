/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/26 17:04:38 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*load_image(mlx_t *window, const char *path, int *error_flag)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		*error_flag = 1;
		return (NULL);
	}
	image = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		*error_flag = 1;
		return (NULL);
	}
	if (!mlx_resize_image(image, BLOCK_SIZE, BLOCK_SIZE))
	{
		*error_flag = 1;
		return (NULL);
	}
	return (image);
}

t_images	*load_images(mlx_t *window)
{
	t_images	*images;
	int			error_flag;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	error_flag = 0;
	images->wall = load_image(window, "./textures/wall.png", &error_flag);
	images->floor = load_image(window, "./textures/floor.png", &error_flag);
	images->collect = load_image(window, "./textures/collect.png", &error_flag);
	images->exit = load_image(window, "./textures/exit.png", &error_flag);
	images->o_exit = load_image(window, "./textures/o_exit.png", &error_flag);
	images->front = load_image(window, "./textures/front.png", &error_flag);
	if (error_flag == 1)
	{
		free(images);
		return (NULL);
	}
	return (images);
}

int	put_image_to_window(mlx_t *window, mlx_image_t *image, t_pos offset, int z)
{
	int	index;

	index = mlx_image_to_window(window, image, \
	offset.x * BLOCK_SIZE, offset.y * BLOCK_SIZE);
	mlx_set_instance_depth(&(image->instances[index]), z);
	return (index);
}

void	put_generic_images(mlx_t *window, t_images *images, \
t_pos offset, char element)
{
	if (element == '0' || element == 'P' || element == 'C')
		put_image_to_window(window, images->floor, offset, 1);
	if (element == '1')
		put_image_to_window(window, images->wall, offset, 1);
	if (element == 'E')
	{
		put_image_to_window(window, images->exit, offset, 1);
		put_image_to_window(window, images->o_exit, offset, 0);
	}
	if (element == 'P')
		put_image_to_window(window, images->front, offset, 3);
}

t_collect	*put_images_to_window(mlx_t *window, t_images *images, \
char **map, t_mapinfo map_info)
{
	int			i;
	char		element;
	t_pos		offset;
	t_collect	*coins_info;
	int			index;

	i = 0;
	coins_info = NULL;
	while (i < map_info.height * map_info.width)
	{
		offset.x = i % map_info.width;
		offset.y = i / map_info.width;
		element = map[offset.y][offset.x];
		put_generic_images(window, images, offset, element);
		if (element == 'C')
		{
			index = put_image_to_window(window, images->collect, offset, 2);
			coinlist_push_back(&coins_info, index, offset.x, offset.y);
		}
		i++;
	}
	return (coins_info);
}
