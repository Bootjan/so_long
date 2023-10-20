/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:43:52 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/20 15:37:11 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
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

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

void	load_window(char **map, t_mapinfo map_info)
{
	mlx_t		*window;
	int			i;
	char		curr_element;

	window = mlx_init(map_info.width * BLOCK_SIZE, map_info.height * BLOCK_SIZE, "So Long!", false);
	if (!window)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), 1);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < map_info.width * map_info.height)
	{
		curr_element = map[i / map_info.height][i % map_info.width];
		if (curr_element == '1')
			put_element(window, map_info, i);
		if (curr_element == '0')
			put_element(window, map_info, i);
		if (curr_element == 'E')
			put_element(window, map_info, i);
		if (curr_element == 'P')
			put_element(window, map_info, i);
		if (curr_element == 'C')
			put_element(window, map_info, i);
		i++;
	}
}



int	main()
{
	// mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)
	mlx_t		*init;

	init = mlx_init(1024, 1024, "So Long!", true);
	if (!init)
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	image = mlx_new_image(init, 128, 128);
	if (!image)
	{
		mlx_close_window(init);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(init, image, 5, 5) == -1)
	{
		mlx_close_window(init);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(init, ft_randomize, init);
	mlx_loop_hook(init, ft_hook, init);

	mlx_loop(init);
	mlx_terminate(init);
	return (EXIT_SUCCESS);
}