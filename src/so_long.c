/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/28 20:29:36 by lade-kon      ########   odam.nl         */
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

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		image->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		image->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		image->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		image->instances[0].x += 64;
}

int	main(int argc, char **argv)
{
	t_game		*game;
	const char	*file;
	int			len;


	if (argc != 2)
		error_message("It's 1 file that is needed as map!!");
	file = argv[1];
	len = ft_strlen(file);
	if (len < 4 || (ft_strncmp(file + len - 4, ".ber", 4)))
		error_message("Incorrect file format! Please provide a .ber file.");
	game = init_game_data(file);
	init_images(game);
	render_map(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}