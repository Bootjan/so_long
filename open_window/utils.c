/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:11:37 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:51:07 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_images(mlx_t *window, t_images *images)
{
	mlx_delete_image(window, images->wall);
	mlx_delete_image(window, images->floor);
	mlx_delete_image(window, images->collect);
	mlx_delete_image(window, images->exit);
	mlx_delete_image(window, images->o_exit);
	mlx_delete_image(window, images->front);
	free(images);
}

void	free_vars(t_images **images, t_gameinfo **gameinfo, \
t_collect **coins_info)
{
	if (*gameinfo)
	{
		free(*gameinfo);
		*gameinfo = NULL;
	}
	if (*images)
	{
		free(*images);
		*images = NULL;
	}
	free_coins_list(coins_info);
}

t_gameinfo	*init_gameinfo_images(mlx_t *window, t_images *images, \
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

t_gameinfo	*init_gameinfo_map(t_gameinfo *gameinfo, \
t_mapinfo map_info, char **map)
{
	gameinfo->total_c = map_info.collectables_n;
	gameinfo->x_exit = map_info.x_exit;
	gameinfo->y_exit = map_info.y_exit;
	gameinfo->map = map;
	return (gameinfo);
}
