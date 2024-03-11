/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/11 21:47:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char **map_to_check;
	int		i;

	i = 0;
	map_to_check = (char **)ft_calloc(game->height, sizeof(char *));
	if (map_to_check == NULL)
		error_message("Memory allocation failed!");
	while (game->map[i] != NULL)
	{
		map_to_check[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_to_check[i] = NULL;

	return (map_to_check);
}

int	flood_fill(t_game *game, int x, int y)
{
	char		**map_to_check;
	static int	collectables;
	static int	exit;

	collectables = 0;
	exit = 0;
	if (collectables == game->collectables && exit == 1)
		return (EXIT_SUCCESS);
	if (map_to_check[y][x] == '1')
		return (EXIT_FAILURE);
	if (map_to_check[y][x] == 'C')
		collectables++;
	if (map_to_check[y][x] == 'E')
		exit++;
	

	map_to_check = copy_map(game);

	print_map(map_to_check);
}
