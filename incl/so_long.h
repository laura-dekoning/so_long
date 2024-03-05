/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/05 21:46:32 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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



#endif