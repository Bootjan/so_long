/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:43:52 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:24:22 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(void *param)
{
	int			x;
	int			y;
	mlx_image_t	*player;
	t_gameinfo	*gameinfo;

	gameinfo = (t_gameinfo *)param;
	player = gameinfo->player;
	x = (player->instances[0].x + 5) / BLOCK_SIZE;
	y = (player->instances[0].y + 5) / BLOCK_SIZE;
	if (gameinfo->total_c == gameinfo->total_collect)
	{
		mlx_set_instance_depth(&(gameinfo->o_exit->instances[0]), 1);
		mlx_set_instance_depth(&(gameinfo->exit->instances[0]), 0);
		if (x == gameinfo->x_exit && y == gameinfo->y_exit)
		{
			ft_printf("You won the game!\n");
			mlx_close_window(gameinfo->window);
		}
	}
}

void	play_game(mlx_t *window, t_gameinfo **gameinfo, \
t_images **images, t_collect **coins_info)
{
	mlx_loop_hook(window, make_move, (void *)*gameinfo);
	mlx_loop_hook(window, collect_coins, (void *)*gameinfo);
	mlx_loop_hook(window, exit_game, (void *)*gameinfo);
	mlx_loop(window);
	mlx_terminate(window);
	free_vars(images, gameinfo, coins_info);
}

mlx_t	*init_window_images(t_images **images, t_collect **coins_info, \
char **map, t_mapinfo map_info)
{
	mlx_t	*window;

	window = mlx_init(map_info.width * BLOCK_SIZE, \
	map_info.height * BLOCK_SIZE, "So Long!", false);
	if (!window)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return (NULL);
	}
	*images = load_images(window);
	if (!*images)
	{
		mlx_close_window(window);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return (NULL);
	}
	*coins_info = put_images_to_window(window, *images, map, map_info);
	if (!*coins_info)
	{
		delete_images(window, *images);
		mlx_close_window(window);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return (NULL);
	}
	return (window);
}

void	load_window(char **map, t_mapinfo map_info)
{
	mlx_t		*window;
	t_images	*images;
	t_gameinfo	*gameinfo;
	t_collect	*coins_info;

	gameinfo = NULL;
	coins_info = NULL;
	images = NULL;
	window = init_window_images(&images, &coins_info, map, map_info);
	if (!window)
		return ;
	gameinfo = init_gameinfo_images(window, images, coins_info);
	if (!gameinfo)
	{
		delete_images(window, images);
		mlx_close_window(window);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return ;
	}
	gameinfo = init_gameinfo_map(gameinfo, map_info, map);
	play_game(window, &gameinfo, &images, &coins_info);
}
