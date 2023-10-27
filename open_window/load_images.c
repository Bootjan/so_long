/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:01:09 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:28 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*load_image(mlx_t *window, const char *path, int *error_flag)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (*error_flag != 0)
		return (NULL);
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
		delete_images(window, images);
		return (NULL);
	}
	return (images);
}
