/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/08 10:17:05 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_game
{
	char		**map;
	int			width;
	int			height;
	t_point		player_pos;
	t_point		exit_pos;
	int			collectables;
	int			collected;
	int			steps;
}				t_game;

/*MAP*/
char	*read_mapfile(const char *file);
t_game	*init_game_data(const char *file);
t_game	*init_game_struct(char **map_as_d_array, int width, int height);
int		count_rows(char **map_as_d_array);
t_point	find_position(char **map_as_d_array, char c);
int		find_amount_collectables(char **map_as_d_array);

void	error_message(char *message);

void	test_initialisation(t_game *game);
void	check_content(char *map);
void	check_invalid_content(int i);
void	check_empty_lines(char *map);
void	check_empty_file(char *map);
void	check_walls(char **map, int width, int height);
void	check_if_map_rectangular(char **map, int width);
void	invalid_content_message(int p, int e, int c);

#endif