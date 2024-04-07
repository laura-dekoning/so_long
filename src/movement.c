/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 17:10:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/07 15:31:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_collectable_or_exit(t_game *game, char **map, int x, int y)
{
	int	to_collect;

	if (map[y][x] == 'C')
	{
		map[y][x] = '0';
		game->collected++;
		to_collect = game->collectables - game->collected;
		ft_printf("Good job. You collected a flower!!\n");
		ft_printf("Flowers collected: %i\n", game->collected);
		ft_printf("Flowers to collect: %i\n", to_collect);
	}
	if (map[y][x] == 'E' && (game->collected == game->collectables))
		mlx_close_window(game->mlx);

}

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
