/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:52 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/20 16:01:05 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
static mlx_image_t	*image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_color(void *param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				245,
				40, // G
				145, // B
				100  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	put_wall(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i)
{
	int			x;
	int			y;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	*image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, *image, x, y); // add security
	mlx_loop_hook(window, ft_color, window);
	*image = NULL;
}

void	put_empty(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i)
{
	int			x;
	int			y;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	*image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, *image, x, y); // add security
	mlx_loop_hook(window, ft_color, window);
	*image = NULL;
}

void	put_exit(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i)
{
	int			x;
	int			y;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	*image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, *image, x, y); // add security
	mlx_loop_hook(window, ft_color, window);
	*image = NULL;
}

void	put_start(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i)
{
	int			x;
	int			y;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	*image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, *image, x, y); // add security
	mlx_loop_hook(window, ft_color, window);
	*image = NULL;
}

void	put_collect(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i)
{
	int			x;
	int			y;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	*image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, *image, x, y); // add security
	mlx_loop_hook(window, ft_color, window);
	*image = NULL;
}