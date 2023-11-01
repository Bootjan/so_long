/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:54:46 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 12:10:08 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	free_map_info(t_mapinfo *map_info)
{
	t_pos	*current;
	t_pos	*next;

	current = map_info->collect_xy;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	map_info->collect_xy = NULL;
}

int	main(int argc, char **argv)
{
	char		**map;
	int			error_flag;
	t_mapinfo	map_info;

	error_flag = 0;
	map = NULL;
	if (argc != 2)
		return (print_error(8));
	ft_bzero(&map_info, sizeof(t_mapinfo));
	map = load_map(argv[1], &map_info, &error_flag);
	if (error_flag != 0)
		return (print_error(error_flag));
	load_window(map, map_info);
	free_map(&map);
	return (EXIT_SUCCESS);
}
