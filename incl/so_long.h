/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/05 09:00:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	int			collectables;
	t_player	player;
	t_point		exit;
	char		**map;
}				t_map;

typedef struct s_player
{
	t_point		player;
	int			collected;
	int			steps;
}				t_player;


#endif