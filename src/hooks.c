/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 19:10:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/05 16:03:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, char **map, int x, int y)
{
	if (map[y - 1][x] != '1')
	{
		game->img.player->instances[0].y -= PIXEL;
		game->player_pos.y--;
		game->steps++;
	}
}

void	move_down(t_game *game, char **map, int x, int y)
{
	if (map[y + 1][x] != '1')
	{
		game->img.player->instances[0].y += PIXEL;
		game->player_pos.y++;
		game->steps++;
	}
}

void	move_left(t_game *game, char **map, int x, int y)
{
	if (map[y][x - 1] != '1')
	{
		game->img.player->instances[0].x -= PIXEL;
		game->player_pos.x--;
		game->steps++;
	}
}

void	move_right(t_game *game, char **map, int x, int y)
{
	if (map[y][x + 1] != '1')
	{
		game->img.player->instances[0].x += PIXEL;
		game->player_pos.x++;
		game->steps++;
	}
}

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	char	**map;

	game = param;
	map = game->map;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, map, game->player_pos.x, game->player_pos.y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, map, game->player_pos.x, game->player_pos.y);
}
