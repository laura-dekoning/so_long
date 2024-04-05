/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/05 17:07:56 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	const char	*file;
	int			len;

	if (argc != 2)
		error_message("It's 1 file that is needed as map!!");
	game = (t_game *)ft_calloc_errorcheck(1, sizeof(t_game));
	file = argv[1];
	len = ft_strlen(file);
	if (len < 4 || (ft_strncmp(file + len - 4, ".ber", 4)))
		error_message("Incorrect file format! Please provide a .ber file.");
	init_game_data(game, file);
	init_images(game);
	render_map(game);
	mlx_key_hook(game->mlx, &keyhooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}