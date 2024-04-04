/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/04 19:22:30 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

int	main(int argc, char **argv)
{
	t_game		*game;
	const char	*file;
	int			len;

	if (argc != 2)
		error_message("It's 1 file that is needed as map!!");
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("Memory allocation failed.\n");
	file = argv[1];
	len = ft_strlen(file);
	if (len < 4 || (ft_strncmp(file + len - 4, ".ber", 4)))
		error_message("Incorrect file format! Please provide a .ber file.");
	init_game_data(game, file);
	init_images(game);
	render_map(game);
	mlx_key_hook(game->mlx, &keyhooks, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}