/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 13:42:55 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/04 13:51:19 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_invalid_content(int i)
{
	if (!(ft_strchr("PEC01\n", i)))
		error_message("Map contains invalid characters");
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

void	check_file(char *map)
{
	check_empty_file(map);
	check_empty_lines(map);
	check_content(map);
}
