/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/10 17:11:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game, char **map_as_d_array, int width, int height)
{
	game->map = map_as_d_array;
	game->width = width;
	game->height = height;
	game->player_pos = find_position(map_as_d_array, 'P');
	game->exit_pos = find_position(map_as_d_array, 'E');
	game->collectables = find_amount_collectables(map_as_d_array);
	game->collected = 0;
	game->steps = 0;
	game->mlx = mlx_init(PIXEL * game->width, PIXEL * game->height, "so_long", false);
	if (!game->mlx)
		error_message("Failed to initiliaze window.");
}

void	init_game_data(t_game *game, const char *file)
{
	char	*map_as_str;
	char	**map_as_d_array;
	char	**floodfill;
	int		width;
	int		height;

	map_as_str = read_mapfile(file);
	check_file(map_as_str);
	map_as_d_array = ft_split(map_as_str, '\n');
	width = ft_strlen(map_as_d_array[0]);
	height = count_rows(map_as_d_array);
	check_map(map_as_d_array, width, height);
	init_game_struct(game, map_as_d_array, width, height);
	floodfill = copy_map(game);
	if (flood_fill(game, floodfill, game->player_pos.x, game->player_pos.y) == false)
		error_message("Floodfill FAILED!");
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
	while(1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_as_str = ft_gnl_strjoin(map_as_str, line);
			free(line);
		}
		else
			break;
	}
	close(fd);
	return (map_as_str);
}
