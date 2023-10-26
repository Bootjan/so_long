/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:43:52 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/26 17:31:39 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_coins_list(t_collect **coins_info)
{
	t_collect	*current;
	t_collect	*next;

	current = *coins_info;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_vars(t_images **images, t_gameinfo **gameinfo, mlx_t *window, t_collect **coins_info)
{
	if (*gameinfo)
	{
		free(*gameinfo);
		*gameinfo = NULL;
	}
	mlx_delete_image(window, (*images)->wall);
	mlx_delete_image(window, (*images)->floor);
	mlx_delete_image(window, (*images)->collect);
	mlx_delete_image(window, (*images)->exit);
	mlx_delete_image(window, (*images)->o_exit);
	mlx_delete_image(window, (*images)->front);
	if (*images)
	{
		free(*images);
		*images = NULL;
	}
	// free_coins_list(coins_info);
}

t_gameinfo	*init_gameinfo_images(mlx_t *window, t_images *images,\
 t_collect *coins_info)
{
	t_gameinfo	*gameinfo;

	gameinfo = malloc(sizeof(t_gameinfo));
	if (!gameinfo)
		return (NULL);
	gameinfo->window = window;
	gameinfo->player = images->front;
	gameinfo->collect = images->collect;
	gameinfo->exit = images->exit;
	gameinfo->o_exit = images->o_exit;
	gameinfo->coins_info = coins_info;
	gameinfo->key_down = 0;
	gameinfo->total_moves = 0;
	gameinfo->total_collect = 0;
	return (gameinfo);
}

t_gameinfo	*init_gameinfo_map(t_gameinfo *gameinfo, t_mapinfo map_info, char **map)
{
	gameinfo->total_c = map_info.collectables_n;
	gameinfo->x_exit = map_info.x_exit;
	gameinfo->y_exit = map_info.y_exit;
	gameinfo->map = map;
	return (gameinfo);
}

void	exit_game(t_gameinfo *gameinfo)
{
	int			x;
	int			y;
	mlx_image_t	*player;

	player = gameinfo->player;
	x = (player->instances[0].x + 5) / BLOCK_SIZE;
	y = (player->instances[0].y + 5) / BLOCK_SIZE;
	if (gameinfo->total_c == gameinfo->total_collect)
	{
		mlx_set_instance_depth(&(gameinfo->o_exit->instances[0]), 1);
		mlx_set_instance_depth(&(gameinfo->exit->instances[0]), 0);
		if (x == gameinfo->x_exit && y == gameinfo->y_exit && \
		mlx_is_key_down(gameinfo->window, MLX_KEY_ENTER))
			mlx_close_window(gameinfo->window);
	}
}

void	play_game(mlx_t *window, t_gameinfo **gameinfo, t_images **images, t_collect **coins_info)
{
	mlx_loop_hook(window, make_move, *gameinfo);
	mlx_loop_hook(window, collect_coins, *gameinfo);
	mlx_loop_hook(window, exit_game, *gameinfo);
	mlx_loop(window);
	free_vars(images, gameinfo, window, coins_info);
	mlx_terminate(window);
	mlx_close_window(window);
}

void	load_window(char **map, t_mapinfo map_info)
{
	mlx_t		*window;
	t_images	*images;
	t_gameinfo	*gameinfo;
	t_collect	*coins_info;

	window = mlx_init(map_info.width * BLOCK_SIZE, \
	map_info.height * BLOCK_SIZE, "So Long!", false);
	if (!window)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return ;
	}
	images = load_images(window);
	if (!images)
	{
		mlx_close_window(window);
		free_vars(&images, &gameinfo, window, &coins_info);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 1);
		return ;
	}
	coins_info = put_images_to_window(window, images, map, map_info);
	gameinfo = init_gameinfo_images(window, images, coins_info);
	gameinfo = init_gameinfo_map(gameinfo, map_info, map);
	play_game(window, &gameinfo, &images, &coins_info);
}
