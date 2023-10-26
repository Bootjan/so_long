/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:59:27 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/26 16:16:31 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(int x, int y, char **map, char direction)
{
	x = (x + 10) / BLOCK_SIZE;
	y = (y + 10) / BLOCK_SIZE;
	if (direction == 'w')
		return (map[y - 1][x] != '1');
	if (direction == 's')
		return (map[y + 1][x] != '1');
	if (direction == 'd')
		return (map[y][x + 1] != '1');
	if (direction == 'a')
		return (map[y][x - 1] != '1');
	return (0);
}

int	key_down(mlx_t *window)
{
	if (mlx_is_key_down(window, MLX_KEY_W))
		return (1);
	if (mlx_is_key_down(window, MLX_KEY_A))
		return (1);
	if (mlx_is_key_down(window, MLX_KEY_S))
		return (1);
	if (mlx_is_key_down(window, MLX_KEY_D))
		return (1);
	return (0);
}

void	move_player(mlx_image_t *player, t_gameinfo *gameinfo, char direction)
{
	if (direction == 'w')
		player->instances[0].y -= BLOCK_SIZE;
	if (direction == 's')
		player->instances[0].y += BLOCK_SIZE;
	if (direction == 'a')
		player->instances[0].x -= BLOCK_SIZE;
	if (direction == 'd')
		player->instances[0].x += BLOCK_SIZE;
	gameinfo->key_down = 1;
	gameinfo->total_moves++;
	ft_printf("Number of moves: %i.\n", gameinfo->total_moves);
}

void	make_move(t_gameinfo *gameinfo)
{
	mlx_t		*window;
	mlx_image_t	*player;
	int			x;
	int			y;

	window = gameinfo->window;
	player = gameinfo->player;
	x = player->instances[0].x;
	y = player->instances[0].y;
	if (!key_down(window))
		gameinfo->key_down = 0;
	if (mlx_is_key_down(window, MLX_KEY_ESCAPE))
		mlx_close_window(window);
	if (mlx_is_key_down(window, MLX_KEY_W) && \
	valid_move(x, y, gameinfo->map, 'w') && gameinfo->key_down == 0)
		move_player(player, gameinfo, 'w');
	if (mlx_is_key_down(window, MLX_KEY_S) && \
	valid_move(x, y, gameinfo->map, 's') && gameinfo->key_down == 0)
		move_player(player, gameinfo, 's');
	if (mlx_is_key_down(window, MLX_KEY_A) && \
	valid_move(x, y, gameinfo->map, 'a') && gameinfo->key_down == 0)
		move_player(player, gameinfo, 'a');
	if (mlx_is_key_down(window, MLX_KEY_D) && \
	valid_move(x, y, gameinfo->map, 'd') && gameinfo->key_down == 0)
		move_player(player, gameinfo, 'd');
}
