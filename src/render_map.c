/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 15:36:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/28 20:32:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if(mlx_image_to_window(game->mlx, game->img.floor, x * PIXEL, y * PIXEL) < 0)
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
			{
				if(mlx_image_to_window(game->mlx, game->img.wall, x * PIXEL, y * PIXEL) < 0 )
					error_message("Failed to put image to window");
			}
			if (game->map[y][x] == 'P')
			{
				if(mlx_image_to_window(game->mlx, game->img.player, x * PIXEL, y * PIXEL) < 0 )
					error_message("Failed to put image to window");
			}
			if (game->map[y][x] == 'E')
			{
				if(mlx_image_to_window(game->mlx, game->img.exit, x * PIXEL, y * PIXEL) < 0 )
					error_message("Failed to put image to window");
			}			
			if (game->map[y][x] == 'C')
			{
				if(mlx_image_to_window(game->mlx, game->img.collectable, x * PIXEL, y * PIXEL) < 0 )
					error_message("Failed to put image to window");
			}
			x++;
		}
		y++;
	}
}
