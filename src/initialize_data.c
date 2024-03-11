/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/11 21:46:12 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game_struct(char **map_as_d_array, int width, int height)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("Memory allocation failed.\n");
	game->map = map_as_d_array;
	game->width = width;
	game->height = height;
	game->player_pos = find_position(map_as_d_array, 'P');
	game->exit_pos = find_position(map_as_d_array, 'E');
	game->collectables = find_amount_collectables(map_as_d_array);
	game->collected = 0;
	game->steps = 0;
	return (game);
}

t_game	*init_game_data(const char *file)
{
	t_game	*data;
	char	*map_as_str;
	char	**map_as_d_array;
	int		width;
	int		height;

	map_as_str = read_mapfile(file);
	check_empty_file(map_as_str);
	check_empty_lines(map_as_str);
	check_content(map_as_str);
	map_as_d_array = ft_split(map_as_str, '\n');
	width = ft_strlen(map_as_d_array[0]);
	height = count_rows(map_as_d_array);
	check_if_map_rectangular(map_as_d_array, width);
	check_walls(map_as_d_array, width, height);
	data = init_game_struct(map_as_d_array, width, height);
	flood_fill(data, data->player_pos.x, data->player_pos.y);
	printf("Floodfill completed succesfully!\n");
	return (data);
}

char	*read_mapfile(const char *file)
{
	int		fd;
	char	*line;
	char	*map_as_str;

	fd = open(file, O_RDONLY);
	map_as_str = ft_calloc(1, 1);
	while(1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_as_str = ft_strjoin(map_as_str, line);
			free(line);
		}
		else
			break;
	}
	close(fd);
	return (map_as_str);
}
