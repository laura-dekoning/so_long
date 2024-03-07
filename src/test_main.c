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

t_game	*initialize_struct(char **map_as_d_array)
{
	t_game	*game;
	int		width;
	int		height;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("Memory allocation failed.\n");
	width = ft_strlen(map_as_d_array[0]);
	height = count_rows(map_as_d_array);
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

t_game	*initialize_data(const char *file)
{
	t_game	*data;
	char	*map_as_str;
	char	**map_as_d_array;

	map_as_str = read_mapfile(file);
	map_as_d_array = ft_split(map_as_str, '\n');
	data = initialize_struct(map_as_d_array);


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
	//Test if data is correctly initiliazed//
	ft_printf("Width:[%i]\n", game->width);
	ft_printf("Height:[%i]\n", game->height);
	ft_printf("Collectables:[%i]\n", game->collectables);
	ft_printf("Collected:[%i]\n", game->collected);
	ft_printf("Steps:[%i]\n", game->steps);
	ft_printf("Player position:[%i][%i]\n", game->player_pos.y, game->player_pos.x);
	ft_printf("Exit position:[%i][%i]\n", game->exit_pos.y, game->exit_pos.x);


	return (0);
}