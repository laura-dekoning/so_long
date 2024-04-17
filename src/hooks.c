/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 19:10:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/17 15:47:54 by lade-kon      ########   odam.nl         */
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
		ft_printf("Steps: %i\n", game->steps);
		check_if_collectable_or_exit(game, map, x, game->player_pos.y);
	}
}

void	move_down(t_game *game, char **map, int x, int y)
{
	if (map[y + 1][x] != '1')
	{
		game->img.player->instances[0].y += PIXEL;
		game->player_pos.y++;
		game->steps++;
		ft_printf("Steps: %i\n", game->steps);
		check_if_collectable_or_exit(game, map, x, game->player_pos.y);
	}
}

void	move_left(t_game *game, char **map, int x, int y)
{
	if (map[y][x - 1] != '1')
	{
		game->img.player->instances[0].x -= PIXEL;
		game->player_pos.x--;
		game->steps++;
		ft_printf("Steps: %i\n", game->steps);
		check_if_collectable_or_exit(game, map, game->player_pos.x, y);
	}
}

void	move_right(t_game *game, char **map, int x, int y)
{
	if (map[y][x + 1] != '1')
	{
		game->img.player->instances[0].x += PIXEL;
		game->player_pos.x++;
		game->steps++;
		ft_printf("Steps: %i\n", game->steps);
		check_if_collectable_or_exit(game, map, game->player_pos.x, y);
	}
}
