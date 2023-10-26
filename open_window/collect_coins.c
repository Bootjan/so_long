/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:07:59 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/26 17:30:36 by bschaafs         ###   ########.fr       */
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
	element->next = NULL;
	return (element);
}

void	coinlist_push_back(t_collect **coins_info, int index, int x, int y)
{
	t_collect	*current;
	t_collect	*element;

	element = create_element(index, x, y);
	if (!element)
		return ; // error handeling
	current = *coins_info;
	if (!current)
	{
		*coins_info = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}

static void	free_el_index(t_collect **coins_info, int index)
{
	t_collect	*current;
	t_collect	*previous;

	if (!*coins_info)
		return ;
	current = *coins_info;
	previous = NULL;
	while (current)
	{
		if (current->index == index)
		{
			if (!previous)
				*coins_info = current->next;
			else
				previous->next = current->next;
			free(current);
			current = NULL;
			return ;
		}
		previous = current;
		current = current->next;
	}
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
		if (current->x == x && current->y == y)
		{
			index = current->index;
			free_el_index(coins_info, index);
			return (index);
		}
		current = current->next;
	}
	return (-1);
}

void	collect_coins(t_gameinfo *gameinfo)
{
	mlx_image_t	*player;
	char		**map;
	int			x;
	int			y;
	int			index;

	player = gameinfo->player;
	map = gameinfo->map;
	x = (player->instances[0].x + 5) / BLOCK_SIZE;
	y = (player->instances[0].y + 5) / BLOCK_SIZE;
	if (map[y][x] != 'C')
		return ;
	index = find_index_collectable(&(gameinfo->coins_info), x, y);
	if (index == -1)
		return ;
	mlx_set_instance_depth(&(gameinfo->collect->instances[index]), 0);
	gameinfo->total_collect++;
}
