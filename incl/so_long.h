/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/06 21:38:47 by lade-kon      ########   odam.nl         */
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
// t_game	*initialize_data(const char *file);
char	**initialize_data(const char *file);
t_game	*initialize_struct(char **map_as_d_array);
int		count_rows(char **map_as_d_array);

void	error_message(char *message);


#endif