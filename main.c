/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:54:46 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:18:43 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	int			error_flag;
	t_mapinfo	map_info;

	error_flag = 0;
	map = NULL;
	if (argc != 2)
		error_flag = 8;
	else
		map = load_map(argv[1], &map_info, &error_flag);
	if (error_flag != 0)
	{
		free_map(&map);
		print_error(error_flag);
		return (0);
	}
	if (error_flag == 0)
	{
		load_window(map, map_info);
		free_map(&map);
	}
	return (0);
}
