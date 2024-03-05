/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/05 21:32:35 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "MLX42.h"

char	*read_mapfile(const char *file);

char	**initialize_data(const char *file)
{
	char	*map_as_str;
	char	**map_as_d_array;

	map_as_str = read_mapfile(file);
	map_as_d_array = ft_split(map_as_str, '\n');


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
	int	i = 0;
	while (map[i] != NULL)
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}


	return (0);
}