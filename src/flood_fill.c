/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/17 16:42:08 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collectables;
	static int	exit;

	if (collectables == game->collectables && exit == 1)
		return (true);
	if (map[y][x] == '1')
		return (false);
	if (map[y][x] == 'C')
		collectables++;
	if (map[y][x] == 'E')
		exit++;
	map[y][x] = '1';
	if (flood_fill(game, map, x + 1, y)
		|| flood_fill(game, map, x - 1, y)
		|| flood_fill(game, map, x, y + 1)
		|| flood_fill(game, map, x, y - 1))
		return (true);
	return (false);
}
