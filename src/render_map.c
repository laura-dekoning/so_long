/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 15:36:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/17 17:35:05 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_flower_or_player(t_game *game, char c, int x, int y)
{
	int	x_pix;
	int	y_pix;

	x_pix = x * PIXEL;
	y_pix = y * PIXEL;
	if (c == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img.flower, x_pix, y_pix) < 0)
			error_message("Failed to put image to window");
	}
	if (c == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->img.player, x_pix, y_pix) < 0)
			error_message("Failed to put image to window");
	}
}

void	place_floor_or_exit(t_game *game, char c, int x, int y)
{
	int	x_pix;
	int	y_pix;

	x_pix = x * PIXEL;
	y_pix = y * PIXEL;
	if (c == '1')
	{
		if (mlx_image_to_window(game->mlx, game->img.wall, x_pix, y_pix) < 0)
			error_message("Failed to put image to window");
	}
	if (c == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img.exit, x_pix, y_pix) < 0)
			error_message("Failed to put image to window");
	}
}

void	fill_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->height)
	{
		x = 0;
		while (x <= game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img.floor, \
				x * PIXEL, y * PIXEL) < 0)
				error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	fill_background(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '0')
				x++;
			if (game->map[y][x] == '1')
				place_floor_or_exit(game, '1', x, y);
			if (game->map[y][x] == 'E')
				place_floor_or_exit(game, 'E', x, y);
			if (game->map[y][x] == 'C')
				place_flower_or_player(game, 'C', x, y);
			if (game->map[y][x] == 'P')
				place_flower_or_player(game, 'P', x, y);
			x++;
		}
		y++;
	}
}
