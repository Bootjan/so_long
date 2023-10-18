/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:53:03 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/18 20:26:26 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct s_lines
{
	char			*line;
	struct s_lines	*next;
}	t_lines;

typedef struct s_mapinfo
{
	int	width;
	int	height;
	int	x_exit;
	int	y_exit;
	int	x_start;
	int	y_start;
	int	collectables_n;
}	t_mapinfo;

# define SIZE_OF_CHAR 1
# define SIZE_OF_CHAR_PTR 8

char	*get_next_line(int fd);
char	*put_line_map(t_lines *lines, int index);
void	ft_lpush_back(t_lines **lines, char *line, int *error_flag);
void	free_list(t_lines **lines, int error_flag);
void	init_map_info(t_mapinfo *map_info);
int		check_validity_map(char **map, t_mapinfo *map_info, int *error_flag);
char	*line_without_nl(int fd);
char	**compute_map(int fd, t_mapinfo *map_info, int *error_flag);
void	free_map(char ***map);
void	print_map(char **map, t_mapinfo map_info);
char	**load_map(t_mapinfo *map_info, int *error_flag);
int		compute_map_width(int current_width, char *line);
void	check_top_and_bottem(char **map, t_mapinfo map_info, int *error_flag);
void	check_left_right(char **map, t_mapinfo map_info, int *error_flag);
void	check_exits(char **map, t_mapinfo *map_info, int *error_flag);
void	check_start(char **map, t_mapinfo *map_info, int *error_flag);
void	check_collectables(char **map, t_mapinfo *map_info, int *error_flag);

/*
* Error values and meaning:
*
* 0 = all good
* 1 = malloc error
* 2 = map validity error
*/

// map[row][column]

#endif