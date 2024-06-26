/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/18 17:11:06 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game, char **map_arr, int width, int height)
{
	game->map = map_arr;
	game->width = width;
	game->height = height;
	game->player_pos = find_position(map_arr, 'P');
	game->exit_pos = find_position(map_arr, 'E');
	game->collectables = find_amount_collectables(map_arr);
	game->collected = 0;
	game->steps = 0;
	game->mlx = mlx_init(PIXEL * width, PIXEL * height, "so_long", false);
	if (!game->mlx)
		error_message("Failed to initiliaze window.");
}

void	init_game_data(t_game *game, const char *file)
{
	char	*map_as_str;
	char	**map_arr;
	int		width;
	int		height;

	map_as_str = read_mapfile(file);
	check_file(map_as_str);
	map_arr = ft_split(map_as_str, '\n');
	if (!map_arr)
	{
		free (map_as_str);
		error_message("Something went wrong");
	}
	width = ft_strlen(map_arr[0]);
	height = count_rows(map_arr);
	check_map(map_arr, width, height);
	init_game_struct(game, map_arr, width, height);
	check_path(game);
	free (map_as_str);
}

char	*read_mapfile(const char *file)
{
	int		fd;
	char	*line;
	char	*map_as_str;

	fd = open(file, O_RDONLY);
	map_as_str = ft_calloc(1, 1);
	if (map_as_str == NULL)
		error_message("Allocation failed!");
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_as_str = ft_gnl_strjoin(map_as_str, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (map_as_str);
}
