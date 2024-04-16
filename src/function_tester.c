#include "so_long.h"

t_point	find_position(char **map_as_arr, char c)
{
	t_point	position;
	int		x;
	int		y;

	y = 0;
	while (map_as_arr[y] != NULL)
	{
		x = 0;
		while (map_as_arr[y][x] != '\0')
		{
			if (map_as_arr[y][x] == c)
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

char	**initialize_data(const char *file)
{
	// t_game	*data;
	char	*map_as_str;
	char	**map_as_arr;

	map_as_str = read_mapfile(file);
	map_as_arr = ft_split(map_as_str, '\n');
	// data = initialize_struct(map_as_arr);


	return (map_as_arr);
}

int	main(int argc, char **argv)
{
	// t_game		*game;
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
	char	**map;
	map = initialize_data(file);
	t_point		test;
	test = find_position(map, 'E');
	ft_printf("[%i][%i]\n", test.y, test.x);


	return (0);
}