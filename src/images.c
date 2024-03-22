/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 14:42:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/22 15:58:45 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	argb_to_rgba(uint32_t *color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = *color & 0xFF;
	g = (*color >> 8) & 0xFF;
	b = (*color >> 16) & 0xFF;
	a = (*color >> 24) & 0xFF;
	*color = r << 24 | g << 16 | b << 8 | a;
}

static void	fix_color_order(mlx_texture_t *txt)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < txt->height)
	{
		j = 0;
		while (j < txt->width)
		{
			argb_to_rgba((uint32_t *)&txt->pixels[(txt->width * i + j) * 4]);
			j++;
		}
		i++;
	}
}

bool	get_texture(mlx_texture_t **img, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*img = NULL;
		return (false);
	}
	close(fd);
	*img = mlx_load_png(path);
	if (!img)
		return (false);
	fix_color_order(*img);
	return (true);
}

void	init_images(t_game *game)
{
	get_texture(&game->img.player, "./assets/cat256x256.png");
	get_texture(&game->img.wall, "assets/wall256x256.png");
	get_texture(&game->img.floor, "assets/floor256x256.png");
	get_texture(&game->img.exit, "assets/floor256x256.png");
	get_texture(&game->img.collectable, "assets/floor256x256.png");
}
