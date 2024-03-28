/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:11:09 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/28 21:13:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	get_image(t_game *game, mlx_image_t **img, mlx_texture_t *txt)
{
	*img = mlx_texture_to_image(game->mlx, txt);
	if (!img)
		error_message("Failed to get image.");
	mlx_delete_texture(txt);
}

void	get_texture(mlx_texture_t **txt, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*txt = NULL;
		error_message("No valid path.");
	}
	close(fd);
	*txt = mlx_load_png(path);
	if (!txt)
		error_message("Failed to load texture.");
}

void	init_images(t_game *game)
{
	get_texture(&game->img.p, "assets/nyancat64x64.png");
	get_image(game, &game->img.player, game->img.p);
	get_texture(&game->img.w, "./assets/rock64x64.png");
	get_image(game, &game->img.wall, game->img.w);
	get_texture(&game->img.f, "./assets/floor64x64.png");
	get_image(game, &game->img.floor, game->img.f);
	get_texture(&game->img.e, "./assets/rocket64x64.png");
	get_image(game, &game->img.exit, game->img.e);
	get_texture(&game->img.c, "./assets/flower64x64.png");
	get_image(game, &game->img.collectable, game->img.c);
}
