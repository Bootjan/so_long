/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:53:03 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/20 15:53:02 by bschaafs         ###   ########.fr       */
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
#include "MLX42.h"

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
	int	path;
}	t_mapinfo;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

# define SIZE_OF_CHAR 1
# define SIZE_OF_CHAR_PTR 8
# define MAX_FD 65535
# define BLOCK_SIZE 48
# define WALL_CLR
# define EMPTY_CLR
# define EXIT_CLR
# define START_CLR
# define COLLECT_CLR

char	*get_next_line(int fd);
char	*put_line_map(t_lines *lines, int index);
void	ft_lpush_back(t_lines **lines, char *line, int *error_flag);
void	free_list(t_lines **lines, int error_flag);
void	init_map_info(t_mapinfo *map_info);
int		check_validity_map(char **map, t_mapinfo *map_info, int *error_flag);
char	*line_without_nl(int fd, int *error_flag);
char	**compute_map(int fd, t_mapinfo *map_info, int *error_flag);
void	free_map(char ***map);
void	print_map(char **map, t_mapinfo map_info);
char	**load_map(char *file, t_mapinfo *map_info, int *error_flag);
int		compute_map_width(int current_width, char *line);
void	check_top_and_bottem(char **map, t_mapinfo map_info, int *error_flag);
void	check_left_right(char **map, t_mapinfo map_info, int *error_flag);
void	check_exits(char **map, t_mapinfo *map_info, int *error_flag);
void	check_start(char **map, t_mapinfo *map_info, int *error_flag);
void	check_collectables(char **map, t_mapinfo *map_info, int *error_flag);
int		cmp_pos(t_pos pos1, t_pos pos2);
t_pos	init_pos(int x, int y);
t_pos	update_curr_pos(t_pos curr_pos, char direction);
int		obj_in_front(char **map, t_pos curr_pos, char direction);
void	check_path(char **map, t_mapinfo *map_info, int *error_flag);
char	**cpy_map(char **map, t_mapinfo map_info);
int		in_arr(char s, char *arr);
void	check_elements(char **map, t_mapinfo map_info, int *error_flag);
void	print_error(int error_flag);

void	load_window(char **map, t_mapinfo map_info);
void	put_wall(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i);
void	put_empty(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i);
void	put_exit(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i);
void	put_start(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i);
void	put_collect(mlx_t *window, mlx_image_t **image, t_mapinfo map_info, int i);

/*
* Error values and meaning:
*
* 0 = all good
* 1 = malloc error
* 2 = too many or no start
* 3 = too many or no exit
* 4 = no collectibles
* 5 = incorrect borders
* 6 = no path
* 7 = invalid character found
* 8 = bad argc
* 9 = txt not found
* 10 = lines not equal
*/

/*
* size of block = 48
*/

// map[row][column]
// map[y][x]

#endif