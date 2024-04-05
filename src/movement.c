/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 17:10:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/05 17:43:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// void	check_if_collectable(t_game *game)
// {
// 	if ()
// }

void	do_movements(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	char	**map;

	game = param;
	map = game->map;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) 
	|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) 
	|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) 
	|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) 
	|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, map, game->player_pos.x, game->player_pos.y);
}
