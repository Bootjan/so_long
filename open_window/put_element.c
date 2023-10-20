/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:52 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/20 15:37:19 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_wall(mlx_t *window, t_mapinfo map_info, int i)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, image, x, y); // add security
	mlx_loop_hook(window, ft_wall_block, window);
}

void	put_empty(mlx_t *window, t_mapinfo map_info, int i)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, image, x, y); // add security
	mlx_loop_hook(window, ft_empty_block, window);
}

void	put_exit(mlx_t *window, t_mapinfo map_info, int i)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, image, x, y); // add security
	mlx_loop_hook(window, ft_exit_block, window);
}

void	put_start(mlx_t *window, t_mapinfo map_info, int i)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, image, x, y); // add security
	mlx_loop_hook(window, ft_start_block, window);
}

void	put_collect(mlx_t *window, t_mapinfo map_info, int i)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	x = i % map_info.width * BLOCK_SIZE;
	y = i / map_info.height * BLOCK_SIZE;
	image = mlx_new_image(window, BLOCK_SIZE, BLOCK_SIZE); // add return on failure
	mlx_image_to_window(window, image, x, y); // add security
	mlx_loop_hook(window, ft_collect_block, window);
}