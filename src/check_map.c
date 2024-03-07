/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/07 23:23:40 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_invalid_content(int i)
{
	if (!(ft_strchr("PEC01\n", i)))
		error_message("Map contains invalid characters");
}

void	invalid_content_message(int p, int e, int c)
{
	if ((p != 1 || e != 1) && c < 1)
		error_message("Map content is not valid!" \
		"Map contains duplicates and no collectables.");
	if (c < 1)
		error_message("Map content is not valid! No collectables available.");
	if (p != 1 || e != 1)
		error_message("Map content is not valid! Map contains duplicates.");
}

void	check_content(char *map)
{
	int	player;
	int	exit;
	int	collectables;
	int	i;

	player = 0;
	exit = 0;
	collectables = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'C')
			collectables++;
		else
			check_invalid_content(map[i]);
		i++;
	}
	invalid_content_message(player, exit, collectables);
}

void	check_empty_lines(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			error_message("Map contains an empty line");
		i++;
	}
}

void	check_empty_file(char *map)
{
	if (map[0] == '\0')
			error_message("Map is empty!!");
}

void	check_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			error_message("Map is not surrounded by walls!");
		
		if (map[height - 1][i] != '1')
			error_message("Map is not surrounded by walls!");

		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
			error_message("Map is not surrounded by walls!");
		if (map[i][width - 1] != '1')
			error_message("Map is not surrounded by walls!");
		i++;
	}
}

void	check_if_map_rectangular(char **map, int width)
{
	int		i;
	size_t	len;

	len = (size_t)width;
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
			error_message("Map is not rectangular!");
		i++;
	}
}
