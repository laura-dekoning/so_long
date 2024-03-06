/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/06 20:18:32 by lade-kon      ########   odam.nl         */
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

t_game	*initialize_struct(char **map_as_d_array)
{
	t_game	*game;

	game->map = map_as_d_array;
	game->width = ft_strlen(map_as_d_array[0]);
	game->height = count_rows(map_as_d_array);
	game->player_pos = find_position(map_as_d_array, "P");
	game->exit_pos = find_position(map_as_d_array, "E");
	return (game);
}

t_game	*initialize_data(const char *file)
{
	t_game	*game;
	char	*map_as_str;
	char	**map_as_d_array;

	map_as_str = read_mapfile(file);
	map_as_d_array = ft_split(map_as_str, '\n');

	initialize_struct(game);


	return (map_as_d_array);
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

int	main(int argc, char **argv)
{
	t_game		*game;
	const char	*file;
	int			len;

	if (argc != 2)
	{
		ft_printf("Incorrect amount of arguments\n");
		return (1);
	}

	file = argv[1];
	len = ft_strlen(file);
	if (len < 4 || (!ft_strncmp(file + len - 4, ".ber", 4) == 0))
	{
		ft_printf("Incorrect file format! Please provide a .ber file.\n");
		return (1);
	}
	game = initialize_data(file);



	return (0);
}