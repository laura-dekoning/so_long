/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/11 16:22:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_game *game)
{
	if (game->map)
		free_map(game->map);
	free(game);
}

void	*ft_calloc_errorcheck(size_t num_elem, size_t size_elem)
{
	void	*ptr;

	ptr = ft_calloc(num_elem, size_elem);
	if (!ptr)
		error_message("Allocation failed.");
	return (ptr);
}
