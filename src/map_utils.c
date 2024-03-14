/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/13 12:00:10 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char **map_as_d_array)
{
	int	i;

	i = 0;
	while (map_as_d_array[i] != NULL)
		i++;
	return (i);
}
int	find_amount_collectables(char **map_as_d_array)
{
	int	c;
	int	x;
	int	y;

	y = 0;
	c = 0;
	while (map_as_d_array[y] != NULL)
	{
		x = 0;
		while (map_as_d_array[y][x] != '\0')
		{
			if (map_as_d_array[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

t_point	find_position(char **map_as_d_array, char c)
{
	t_point	position;
	int		x;
	int		y;

	y = 0;
	while (map_as_d_array[y] != NULL)
	{
		x = 0;
		while (map_as_d_array[y][x] != '\0')
		{
			if (map_as_d_array[y][x] == c)
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

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
