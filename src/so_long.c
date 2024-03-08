/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/08 10:04:58 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




int	main(int argc, char **argv)
{
	t_game		*game;
	const char	*file;
	int			len;

	if (argc != 2)
	{
		ft_printf("Incorrect amount of arguments\n");
		return (1);
	}

	file = argv[1];
	len = ft_strlen(file);
	if (len < 4 || (!ft_strncmp(file + len - 4, ".ber", 4) == 0))
	{
		ft_printf("Incorrect file format! Please provide a .ber file.\n");
		return (1);
	}
	game = init_game_data(file);
	test_initialisation(game);



	return (0);
}