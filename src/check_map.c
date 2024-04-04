/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/04 13:49:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_mapsize(int width, int height)
{
	int	m_width;
	int	m_height;

	m_width = 0;
	m_height = 0;
	mlx_get_monitor_size(0, &m_width, &m_height);
	if (!m_width || !m_height)
	{
		m_width = 3840;
		m_height = 2160;
	}
	if (m_width < (width * PIXEL))
		error_message("Map is too big!!");
	if (m_height < (height * PIXEL))
		error_message("Map is too big!!");
}

void	check_map(char **map, int width, int height)
{
	check_mapsize(width, height);
	check_if_map_rectangular(map, width);
	check_walls(map, width, height);
}
