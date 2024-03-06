#include "so_long.h"

int	count_rows(char **map_as_d_array)
{
	int	i;

	i = 0;
	while (map_as_d_array[i] != NULL)
		i++;
	return (i);
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
	char	**map_as_d_array;

	map_as_str = read_mapfile(file);
	map_as_d_array = ft_split(map_as_str, '\n');
	// data = initialize_struct(map_as_d_array);


	return (map_as_d_array);
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
	int		rows;
	rows = count_rows(map);
	ft_printf("[%i]\n", rows);


	return (0);
}