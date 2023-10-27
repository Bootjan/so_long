/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:07:59 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:59:20 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_collect	*create_element(int index, int x, int y)
{
	t_collect	*element;

	element = malloc(sizeof(t_collect));
	if (!element)
		return (NULL);
	element->index = index;
	element->x = x;
	element->y = y;
	element->taken = false;
	element->next = NULL;
	return (element);
}

int	coinlist_push_back(t_collect **coins_info, int index, int x, int y)
{
	t_collect	*current;
	t_collect	*element;

	element = create_element(index, x, y);
	if (!element)
		return (0);
	current = *coins_info;
	if (!current)
	{
		*coins_info = element;
		return (1);
	}
	while (current->next)
		current = current->next;
	current->next = element;
	return (1);
}

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
	*coins_info = NULL;
}

int	find_index_collectable(t_collect **coins_info, int x, int y)
{
	t_collect	*current;
	int			index;

	if (!coins_info)
		return (-1);
	current = *coins_info;
	while (current)
	{
		if (current->x == x && current->y == y && current->taken == false)
		{
			current->taken = true;
			return (current->index);
		}
		current = current->next;
	}
	return (-1);
}

void	collect_coins(void *param)
{
	mlx_image_t	*player;
	int			x;
	int			y;
	int			index;
	t_gameinfo	*gameinfo;

	gameinfo = (t_gameinfo *)param;
	player = gameinfo->player;
	x = (player->instances[0].x + 5) / BLOCK_SIZE;
	y = (player->instances[0].y + 5) / BLOCK_SIZE;
	if (gameinfo->map[y][x] != 'C')
		return ;
	index = find_index_collectable(&(gameinfo->coins_info), x, y);
	if (index == -1)
		return ;
	mlx_set_instance_depth(&(gameinfo->collect->instances[index]), 0);
	gameinfo->total_collect++;
}
