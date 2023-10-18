/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:54:46 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/18 20:21:32 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char		**map;
	int			error_flag;
	t_mapinfo	map_info;

	error_flag = 0;
	map = load_map(&map_info, &error_flag);
	if (!map)
		return (0); // maybe print something
	print_map(map, map_info);
	free_map(&map);
}
